//
// Created by micha on 24.04.2020.
//


#include "basics.h"

basics::basics(std::string name, int alter) :m_name(name) {
    m_alter = alter;
    std::cout << "Init " << name << " ist " << alter << " jahre alt"<<std::endl;
}

basics::~basics() {
    std::cout << m_name << " wird zerstört"<< std::endl;
}

bool basics::init(bool what_to_return) {
    return what_to_return;
}

void basics::update() {
    std::cout << "Update "<<m_name<< std::endl;
}
