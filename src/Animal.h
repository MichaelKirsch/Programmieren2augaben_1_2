#pragma once

#include <iostream>
#include <string>
#include "RenderAble.h"
class Animal : public RenderAble{
public:
    Animal(std::string name, int age);
    ~Animal();
    const std::string& getName(){return m_name;};
    bool init() override; //method is empty
    void update()override;
    void render() override;

private:
    int m_age = -1; //debug purpose, you can later check for -1 to see if init didnt work
    const std::string m_name = "default"; //name wont change so its const
};


