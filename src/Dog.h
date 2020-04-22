#pragma once

#include "Animal.h"

enum class dogtypes {
    underdog, maddog, default_dog
};

class Dog : public Animal {
public:
    Dog(std::string name, int age, dogtypes types, int bark_volume);

    void bark();

    virtual ~Dog();

private:
    dogtypes m_type = dogtypes::default_dog;
    int m_bark_volume = -1;
};


