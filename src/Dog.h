#pragma once

#include "Animal.h"

enum class dogtypes {
    underdog, maddog, default_dog
};
//hund erbt public von Animal. Dog bekommt noch einen enum für seine Rasse
//ansonsten gleicher Ablauf wie bei Animal
class Dog : public Animal {
public:
    Dog(std::string name, int age, dogtypes types, int bark_volume);
    //hund bekommt eine memberfunktion bark
    //von animal werden keine Methoden überschrieben
    void bark();

    virtual ~Dog(); //virtueller destruktor für den fall dass etwas von hund erbt und hund seinen destruktor nicht
    //verlieren darf

private:
    dogtypes m_type = dogtypes::default_dog;
    int m_bark_volume = -1;
};


