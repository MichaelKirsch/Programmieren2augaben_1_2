#pragma once

#include <iostream>
#include <string>
#include "RenderAble.h"

class Animal : public RenderAble //klasse Animal RenderAble alle Public Methoden.
        {
public:
    Animal(std::string name, int age); //konstruktor mit eingabewerten

    ~Animal(); //destruktor der Klasse

    const std::string &getName() { return m_name; }; //getter methode macht hier eigentlich keinen sinn
    //weil getter in setter in c++ nur eingesetzt werden sollten wenn das getten oder setten die klasse
    //Verändert

    bool init() override; //Methoden von Renderable werden überschrieben
    void update() override;
    void render() override;

private:
    int m_age = -1; //deklaration der Membervariablen mit Anfangswerten
    const std::string m_name = "default"; //der name wird sich nicht ändern daher machen ihn const
};


