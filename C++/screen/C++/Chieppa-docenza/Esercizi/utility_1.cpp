#include <iostream>
#include <map>
#include <string>
#include <optional>

// Funzione che ritorna optional<string>
std::optional<std::string> trovaStudente(const std::map<int, std::string>& studenti, int id) {
    auto it = studenti.find(id);
    if (it != studenti.end()) {
        return it->second;
    }
    return std::nullopt;  // Ritorna nulla se non trovato
}

int main() {
    std::map<int, std::string> studenti = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"},
        {4, "Diana"},
        {5, "Eve"}
    };
    
    // Test: ID che esiste
    if (auto nome = trovaStudente(studenti, 3)) {
        std::cout << "ID 3: " << *nome << '\n';
    }
    
    // Test: ID che non esiste
    if (auto nome = trovaStudente(studenti, 10)) {
        std::cout << "ID 10: " << *nome << '\n';
    } else {
        std::cout << "ID 10: Studente non trovato\n";
    }
    
    // Test: Altro ID che esiste
    if (auto nome = trovaStudente(studenti, 1)) {
        std::cout << "ID 1: " << *nome << '\n';
    }
    
    // Test: Altro ID che non esiste
    if (auto nome = trovaStudente(studenti, 99)) {
        std::cout << "ID 99: " << *nome << '\n';
    } else {
        std::cout << "ID 99: Studente non trovato\n";
    }
    
    return 0;
}
