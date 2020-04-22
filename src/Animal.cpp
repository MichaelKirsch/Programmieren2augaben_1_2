
#include "Animal.h"

Animal::Animal(std::string name, int age) : m_name(name){
    m_age = age;
    std::cout << "Animal " << m_name << " gets created"<<std::endl;
}

Animal::~Animal() {
    std::cout << "Animal " << m_name << " gets destoyed"<<std::endl;
}

void Animal::render() {
    RenderAble::render();
}

bool Animal::init() {
    RenderAble::init();
}

void Animal::update() {
    RenderAble::update();
}
