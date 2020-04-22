#pragma once
#include <iostream>

class RenderAble {
public:
    RenderAble() = default;
    virtual ~RenderAble() = default;
    virtual void update();
    virtual bool init();
    virtual void render();
};


