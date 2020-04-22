//
// Created by micha on 21.04.2020.
//

#include "Dog.h"

Dog::Dog(std::string name, int age, dogtypes types, int bark_volume) : Animal(name, age) {
    m_type = types;
    m_bark_volume = bark_volume;
    std::cout << "Dog " << Animal::getName() << " was created" << std::endl;
}

void Dog::bark() {
    std::cout << "Dog " << Animal::getName() << " is barking with volume " << m_bark_volume << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog " << Animal::getName() << " gets destroyed" << std::endl;
}
