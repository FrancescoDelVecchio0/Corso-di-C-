#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> rubrica;
    
    // Aggiungi 3 persone
    rubrica["Alice"] = "123-456-7890";
    rubrica["Bob"] = "098-765-4321";
    rubrica["Charlie"] = "555-123-4567";
    
    // Stampa numero di Alice
    if (rubrica.find("Alice") != rubrica.end()) {
        std::cout << "Numero di Alice: " << rubrica["Alice"] << '\n';
    }

    // Verifica se Diana è in rubrica
    if (rubrica.find("Diana") != rubrica.end()) {
        std::cout << "Diana è in rubrica: " << rubrica["Diana"] << '\n';
    } else {
        std::cout << "Diana non è in rubrica\n";
    }

    return 0;
}