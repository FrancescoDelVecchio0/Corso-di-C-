#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::vector<std::string> nomi = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank"};
    std::vector<std::string> risultato;
    
    // Estrai i nomi con lunghezza > 4
    for (const auto& nome : nomi) {
        if (nome.length() > 4) {
            risultato.push_back(nome);
        }
    }
    
    // Converti in maiuscolo
    for (auto& nome : risultato) {
        std::transform(nome.begin(), nome.end(), nome.begin(),
                       [](unsigned char c) { return std::toupper(c); });
    }
    
    // Ordina alfabeticamente
    std::sort(risultato.begin(), risultato.end());
    
    // Inverti la lista ottenuta
    std::reverse(risultato.begin(), risultato.end());
    
    // Stampa il risultato
    std::cout << "Risultato: ";
    for (const auto& nome : risultato) {
        std::cout << nome << " ";
    }
    std::cout << '\n';
    
    return 0;
}
