#include <iostream>
#include <string>
#include <map>
#include <string>


/*
int main()
{
	std::map<std::string, int> frequenza;

	std::string parole[] = { "ciao", "mondo", "ciao", "test", "mondo", "ciao" };

	
	for (const auto& parola : parole) {
		frequenza[parola]++;
	}

	for (const auto& entry : frequenza) {
		std::cout << entry.first << ": " << entry.second << std::endl;
	}


	return 0;
}*/

int main() {
    std::map<std::string, int> frequenza;
    std::string parole[] = { "ciao", "mondo", "ciao", "test", "mondo", "ciao" };
    // SCRIVI QUI: itera e incrementa
    for (const auto& parola : parole) {
        frequenza[parola]++;
    }
    // SCRIVI QUI: stampa il risultato
    for (const auto& entry : frequenza) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }


    std::map<std::string, std::string> rubrica;
    // SCRIVI QUI: aggiungi 3 persone
    rubrica["Alice"] = "123-456-7890";
    rubrica["Bob"] = "234-567-8901";
    rubrica["Charlie"] = "345-678-9012";
    // SCRIVI QUI: stampa numero di Alice
    std::cout << "Numero di Alice: " << rubrica["Alice"] << std::endl;
    // SCRIVI QUI: verifica se Diana è in rubrica
    if (rubrica.find("Diana") != rubrica.end()) {
        std::cout << "Diana è in rubrica." << std::endl;
    }
    else {
        std::cout << "Diana non è in rubrica." << std::endl;
    }




    return 0;
}