#pragma once

#include <iostream>

//RenderAble is a virtual class. You will need virtual classes if you want to make sure that all the classes that
//derive from them will be compatible. So for example every class in a game engíne will need to be init, rendered,
//and updated from time to time. And to make sure that we can use those methods on all of our objects in our game we
//will make them derive from this base class. Virtual classes cant be created to objects, only derived classes can
class RenderAble {
public:
    RenderAble() = default;

    virtual ~RenderAble() = default;

    virtual void update();

    virtual bool init();

    virtual void render();
};


