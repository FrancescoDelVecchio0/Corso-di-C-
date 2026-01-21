#pragma once
#include <iostream>
#include "Orco.h"
void Orco ::attacca() const
{
	std::cout << "Clava!" << std::endl;
    
}

Orco:: ~Orco()
{
    std::cout << "Orco distrutto" << std::endl;
}