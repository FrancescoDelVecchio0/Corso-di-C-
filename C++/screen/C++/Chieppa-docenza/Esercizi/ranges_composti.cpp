#include <ranges>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Pipeline complessa, leggibile!
    auto result = v
        | std::views::filter([](int x) { return x % 2 == 0; })  // pari
        | std::views::transform([](int x) { return x * x; })     // quadrato
        | std::views::take(3)                                    // primi 3
        | std::views::reverse;                                   // inverti

    for (int x : result) {
        std::cout << x << " ";  // 64 16 4
    }
}

// Risultato: 36 16 4
