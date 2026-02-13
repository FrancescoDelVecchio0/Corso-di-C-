#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <mutex>

std::mutex cout_mtx;

void process_file(const std::string& filename) {
    {
        std::scoped_lock lock(cout_mtx);
        std::cout << "Processing " << filename << "...\n";
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    {
        std::scoped_lock lock(cout_mtx);
        std::cout << "Finished " << filename << "\n";
    }
}

int main() {
    std::vector<std::string> files = {
        "document1.txt", "document2.txt", "document3.txt",
        "document4.txt", "document5.txt"
    };

    auto start = std::chrono::high_resolution_clock::now();
    {
        std::vector<std::jthread> threads;
        for (const auto& file : files) {
            threads.emplace_back(process_file, file);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\nTempo totale: " << duration.count() << "ms\n";
    std::cout << "(Sequenziale sarebbe stato ~500ms)\n";

    return 0;
}