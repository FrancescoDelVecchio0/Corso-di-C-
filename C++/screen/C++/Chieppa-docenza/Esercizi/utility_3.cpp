#include <iostream>
#include <tuple>
#include <string>

int main() {
    // Crea una tupla con: nome, livello, salute
    std::tuple<std::string, int, int> personaggio = {"Aragorn", 25, 100};
    
    // Usa structured binding per accedere ai dati
    auto [nome, livello, salute] = personaggio;
    
    // Stampa le informazioni
    std::cout << "Nome: " << nome << '\n';
    std::cout << "Livello: " << livello << '\n';
    std::cout << "Salute: " << salute << '\n';
    
    return 0;
}
