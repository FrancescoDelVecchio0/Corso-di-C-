#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

std::vector<int> shared_list;
std::mutex list_mtx;

void add_numbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::scoped_lock lock(list_mtx);
        shared_list.push_back(i);
    }
}

int main() {
    std::jthread t1(add_numbers, 1, 10);
    std::jthread t2(add_numbers, 11, 20);
    std::jthread t3(add_numbers, 21, 30);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Lista finale contiene " << shared_list.size() << " elementi\n";
    std::cout << "Attesi: 30 elementi\n";

    return 0;
}