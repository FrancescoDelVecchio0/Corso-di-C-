//
// Created by crist on 01/02/2026.
//
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> frequenza;

    std::string parole[] = {"ciao", "mondo", "ciao", "test", "mondo", "ciao"};

    // Itera e incrementa il contatore
    for (const auto& parola : parole) {
        frequenza[parola]++;
    }

    // Stampa il risultato in ordine alfabetico
    for (const auto& [parola, count] : frequenza) {
        std::cout << parola << ": " << count << '\n';
    }

    return 0;
}
