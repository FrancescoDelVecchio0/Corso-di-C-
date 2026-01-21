#pragma once
#include <iostream>
class Nemico {
public:
    virtual void attacca() const = 0;
    virtual ~Nemico()
    {
        std::cout << "Nemico distrutto" << std::endl;
    }
};
