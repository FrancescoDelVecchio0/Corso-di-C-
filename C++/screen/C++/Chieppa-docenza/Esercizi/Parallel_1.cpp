#include <algorithm>
#include <execution>
#include <vector>
#include <iostream>
#include <chrono>

int main() {
    std::vector<int> data(10'000'000, 1);
    std::vector<int> result(data.size());

    // 1. Sequential
    auto start_seq = std::chrono::high_resolution_clock::now();
    std::transform(std::execution::seq,
        data.begin(), data.end(),
        result.begin(),
        [](int x) { return x * 2 + 1; });
    auto end_seq = std::chrono::high_resolution_clock::now();

    // Verifica risultato
    std::cout << "Primo elemento dopo seq: " << result[0] << " (atteso: 3)\n";

    // Reset
    std::fill(result.begin(), result.end(), 0);

    // 2. Parallel
    auto start_par = std::chrono::high_resolution_clock::now();
    std::transform(std::execution::par,
        data.begin(), data.end(),
        result.begin(),
        [](int x) { return x * 2 + 1; });
    auto end_par = std::chrono::high_resolution_clock::now();

    std::cout << "Primo elemento dopo par: " << result[0] << " (atteso: 3)\n";

    // Reset
    std::fill(result.begin(), result.end(), 0);

    // 3. Parallel + SIMD
    auto start_par_unseq = std::chrono::high_resolution_clock::now();
    std::transform(std::execution::par_unseq,
        data.begin(), data.end(),
        result.begin(),
        [](int x) { return x * 2 + 1; });
    auto end_par_unseq = std::chrono::high_resolution_clock::now();

    std::cout << "Primo elemento dopo par_unseq: " << result[0] << " (atteso: 3)\n\n";

    // Calcola tempi
    auto seq_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_seq - start_seq);
    auto par_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_par - start_par);
    auto par_unseq_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_par_unseq - start_par_unseq);

    std::cout << "=== RISULTATI ===\n";
    std::cout << "Sequential:      " << seq_ms.count() << "ms  (baseline)\n";
    std::cout << "Parallel:        " << par_ms.count() << "ms  (speedup: "
        << (float)seq_ms.count() / par_ms.count() << "x)\n";
    std::cout << "Parallel+SIMD:   " << par_unseq_ms.count() << "ms  (speedup: "
        << (float)seq_ms.count() / par_unseq_ms.count() << "x)\n";
}