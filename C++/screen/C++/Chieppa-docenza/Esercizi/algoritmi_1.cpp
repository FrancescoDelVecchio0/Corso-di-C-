#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numeri = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::vector<int> pari;
    
    // Estrai i numeri pari
    for (int num : numeri) {
        if (num % 2 == 0) {
            pari.push_back(num);
        }
    }
    
    // Raddoppia ogni numero estratto
    for (int& num : pari) {
        num *= 2;
    }
    
    // Ordina il risultato
    std::sort(pari.begin(), pari.end());
    
    // Stampa il risultato
    std::cout << "Risultato: ";
    for (int num : pari) {
        std::cout << num << " ";
    }
    std::cout << '\n';
    
    return 0;
}
