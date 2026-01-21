#pragma once
#include <iostream>
#include "Arciere.h"
void Arciere::attacca() const
{
	std::cout << "Freccia!" << std::endl;
};

Arciere:: ~Arciere()
{
	std::cout << "Arciere distrutto" << std::endl;
}