#include <iostream>
#include <utility>

// Funzione che ritorna pair<int, int>
std::pair<int, int> get_posizione() {
    return {10, 20};
}

int main() {
    // Usa structured binding per estrarre i valori
    auto [x, y] = get_posizione();
    
    std::cout << "Coordinate: x = " << x << ", y = " << y << '\n';
    
    return 0;
}
