#pragma once

#include <string>
#include <iostream>
class basics {
public:
    basics(std::string name, int alter);
    bool init(bool what_to_return);
    void update();
    ~basics();

private:
    const std::string m_name;
    int m_alter;
};


