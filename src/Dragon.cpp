//
// Created by micha on 21.04.2020.
//

#include "Dragon.h"

Dragon::Dragon(std::string name, int age, int feuerFarbe) : Animal(name, age) // init the animal part of the dragon
{
    std::cout << "Dragon gets created" << std::endl;
    m_feuerfarbe = feuerFarbe;
}

Dragon::~Dragon() {
    std::cout << "Dragon gets destoyed" << std::endl;
}

void Dragon::feuerspeien() {
    std::cout << "Dragon " << Animal::getName() << " spits fire with color " << m_feuerfarbe << std::endl;
}
