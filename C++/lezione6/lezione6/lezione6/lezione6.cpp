// lezione6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::vector<int> numeri = {3, 1, 4, 1, 5, 9, 1, 6, 5, 3, 5 };
	std::vector<int> pari;


	// estrai numeri pari 
	for (int num : numeri) {
		/*if (num % 2 == 0) {
			pari.push_back(num);
			
		}*/
		std::copy_if(numeri.begin(), numeri.end(), std::back_inserter(pari),
			[](int n) { return n % 2 == 0; });
	}
	//raddopia ogni numero estrato
	for (int& num : pari) {
		num *= 2;
	}

	//ordina il risultato
	std::sort(pari.begin(), pari.end());
	//stampa il risultato
	for (int num : pari) {
		std::cout << num << " ";
	}



    std::cout << "Hello World!\n";
}


