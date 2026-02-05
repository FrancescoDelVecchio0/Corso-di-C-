// lezione8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <optional>
#include <tuple>
#include <string>
#include <map>
#include <expected>
#include <utility>

std::map<int, std::string> studenti = {
	{1, "Piero"},
	{2, "Giovanni"},
	{3, "Maria"}
};

std::optional<std::string> trovaStudente(int id) {
	auto it = studenti.find(id);
	if (it != studenti.end()) {
		return it->second;
	}
	return std::nullopt; 
}
std::optional<pair<int, int>> validecordinate(int x, int y) {
	if (x >= 0 && y >= 0) {
		return std::make_pair(x, y);
	}
	return std::nullopt;
}

int main()
{
	// testare se id esiste nella mappa
	int id = 5;
	auto nome = trovaStudente(id);
	if (nome) {
		std::cout << "Nome dello studente con ID " << id << ": " << *nome << "\n";
	} else {
		std::cout << "Studente con ID " << id << " non trovato.\n";
	}


// pair
	auto posizione = std::make_pair(10, 20);
	

	auto [x, y] = posizione;

    std::cout << "X:" << x << " Y: " << y << "\n";


// tuplea

	auto player = std::make_tuple("Piero", 10, 20);

	auto[nomep, level, health] = player;

	std::cout << "Nome: " << nomep << " Livello: " << level << " Salute: " << health << "\n";

	return 0;
}

