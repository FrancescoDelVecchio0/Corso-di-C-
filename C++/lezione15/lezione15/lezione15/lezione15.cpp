#include <execution>  
#include <algorithm>
#include <vector>
#include <chrono>   
#include <iostream>

int main()
{
	std::vector<int> data(10000000, 1);
	std::vector<int> result(data.size());

	// sequenziale
	auto start_seq = std::chrono::high_resolution_clock::now();
	std::transform(std::execution::seq, data.begin(), data.end(), result.begin(),
		[](int x) { return x * 2+1; });
	auto end_seq = std::chrono::high_resolution_clock::now();

	// parallelo
	auto start_par = std::chrono::high_resolution_clock::now();
	std::transform(std::execution::par, data.begin(), data.end(), result.begin(),
		[](int x) { return x * 2+1; });
	auto end_par = std::chrono::high_resolution_clock::now();

	std::fill(result.begin(), result.end(), 0);

	// parallelo + SIMD
	auto start_par_unseq = std::chrono::high_resolution_clock::now();
	std::transform(std::execution::par_unseq, data.begin(), data.end(), result.begin(),
		[](int x) { return x * 2+1; });

	auto end_par_unseq = std::chrono::high_resolution_clock::now();


	auto seq_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_seq - start_seq);
	auto par_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_par - start_par);
	auto par_unseq_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_par_unseq - start_par_unseq);

    std::cout << "Sequienziale: " << seq_ms.count() << " ms\n";
	std::cout << "Parallelo: " << par_ms.count() << " ms\n";
	std::cout << "Parallelo e SIMD; " << par_unseq_ms.count() << " ms\n";






}

