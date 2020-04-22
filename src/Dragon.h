#pragma once

#include "Animal.h"

class Dragon : public Animal{
public:
    Dragon(std::string name, int age, int feuerFarbe);
    ~Dragon();
    void feuerspeien();
private:
    int m_feuerfarbe = 0;
};


