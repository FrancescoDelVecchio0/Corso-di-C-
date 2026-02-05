// lezione9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <string>

int main()
{
	std::vector <int> v = { 1,2,3,4,5,6,7,8,9,10 };

	int risultato = std::accumulate(v.begin(), v.end(), 0, [](int a, int b) {
		if(b%2==0)
			return a + b;
		else
			return a;
	}); 

	std::cout << "La somma dei numeri pari e': " << risultato << std::endl;




	std::vector <double> Prezzo = { 100,200,300 };
	std::vector <std::string> Nomi = { "Mela","Pane","Acqua" };

	double spesa = std::accumulate(Prezzo.begin(), Prezzo.end(), 0, [](int a, int b) {
		if (b % 2 == 0)
			return a + b;
		else
			return a;
		});
	std::cout << "La spesa e': " << spesa << std::endl;


	int sconto = std::accumulate(Prezzo.begin(), Prezzo.end(), 0, [](int a, int b) {
		if (b % 2 == 0)
			return a + b * 0.1;
		else
			return b;
		});
	std::cout << "Lo sconto e': " << sconto << std::endl;

	//prezzo finale 
	int prezzo_finale = spesa - sconto;

	//stampa sia il prezzo finale che i nomi dei prodotti acquistati
		


    std::cout << "Hello World!\n";
}
