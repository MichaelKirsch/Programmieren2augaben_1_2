
#include "Animal.h"

Animal::Animal(std::string name, int age) : m_name(name) //name ist const daher muss es sofort deklariert werden
{
    m_age = age;  // private Variable wird überschrieben
    std::cout << "Animal " << m_name << " gets created" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal " << m_name << " gets destoyed" << std::endl;
}

void Animal::render() {
    RenderAble::render(); //Aufruf der Base Klassen Methode
}

bool Animal::init() {
    //überschreiben der init Methode
    std::cout << "Animal " << m_name << " init" << std::endl;
}

void Animal::update() {
    //hier aufrufen der Base und der eigenen Membermethode
    RenderAble::update();
    std::cout << "Animal " << m_name << " update" << std::endl;
}
