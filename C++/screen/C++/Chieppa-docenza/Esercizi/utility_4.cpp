#include <iostream>
#include <optional>
#include <utility>

// Funzione che ritorna optional<pair<int, int>>
std::optional<std::pair<int, int>> validaCoordinate(int x, int y) {
    if (x > 0 && y > 0) {
        return std::pair{x, y};
    }
    return std::nullopt;
}

int main() {
    // Test: coordinate valide
    if (auto coord = validaCoordinate(10, 20)) {
        auto [x, y] = *coord;  // Structured binding
        std::cout << "Coordinate valide: (" << x << ", " << y << ")\n";
    }
    
    // Test: coordinate non valide (x <= 0)
    if (auto coord = validaCoordinate(-5, 20)) {
        auto [x, y] = *coord;
        std::cout << "Coordinate valide: (" << x << ", " << y << ")\n";
    } else {
        std::cout << "Coordinate non valide: x <= 0\n";
    }
    
    // Test: coordinate non valide (y <= 0)
    if (auto coord = validaCoordinate(10, -3)) {
        auto [x, y] = *coord;
        std::cout << "Coordinate valide: (" << x << ", " << y << ")\n";
    } else {
        std::cout << "Coordinate non valide: y <= 0\n";
    }
    
    // Test: entrambe <= 0
    if (auto coord = validaCoordinate(0, 0)) {
        auto [x, y] = *coord;
        std::cout << "Coordinate valide: (" << x << ", " << y << ")\n";
    } else {
        std::cout << "Coordinate non valide: entrambe <= 0\n";
    }
    
    return 0;
}