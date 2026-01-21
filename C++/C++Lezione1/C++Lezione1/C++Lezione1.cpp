// C++Lezione1.cpp 

#include <iostream>
#include <vector>
#include "Nemico.h"
#include "Orco.h"
#include "Arciere.h"


int main()
{

    std::vector<std::unique_ptr<Nemico>> nemici;

    nemici.push_back(std::make_unique<Orco>());
    nemici.push_back(std::make_unique<Arciere>());

    for (const auto& nemico : nemici) {
        nemico->attacca();
    }

    return 0;
};

