
#include <iostream>
#include <vector>
#include<thread>
#include<chrono>
#include<mutex>




std::mutex cout_mutex;
void process_file(const std::string& filename)
{
   
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Processed file: " << filename << std::endl;
}

int main()
{

	std::vector<std::string> files = { "pongo.txt", "piero.txt", "mattia.txt" };
	auto start = std::chrono::high_resolution_clock::now(); { // fare tutti i thread e join senza chiamarli
		std::vector<std::jthread> threads;
		for (const auto& file : files) {
			threads.emplace_back(process_file, file);
		}
	}
	//std::jthread t1(process_file, files[0]);
	//std::jthread t2(process_file, files[1]);
	//std::jthread t3(process_file, files[2]);

	//t1.join();
	//t2.join();
	//t3.join();

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);	



    std::cout << "Tempo totale: "<< duration.count() << "ms\n";
	std::cout << "Sequnziale sarebbe stato 500ms\n";
	return 0;
}


