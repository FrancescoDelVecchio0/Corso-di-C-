// lezione7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

int main()
{
	std::vector<std::string> nomi = { "Alice", "Bob", "Charlie", "Diana", "Eve", "Frank"};
	std::vector<std::string> risultato;

	// estrai nomi lunghezza >4
	for (const auto& nome : nomi) {
		if (nome.length()>4) {
			risultato.push_back(nome);

		}
	}
	
	// convertire in maiuscolo con std::to_upper
	for (auto& nome : nomi) {
		std::transform(nome.begin(), nome.end(), nome.begin(), ::toupper);
	}
	//ordina alfabeticamente 
	std::sort(nomi.begin(), nomi.end());

	//inverti l'ordine
	std::reverse(nomi.begin(), nomi.end());

	// stampa il risultato
	for (const auto& nome : nomi) {
		std::cout << nome << "\n";
	}


   
}

