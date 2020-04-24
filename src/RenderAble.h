#pragma once

#include <iostream>

//Renderable stellt die virtuelle klasse dar von der alle Tiere erben werden.
//durch das erben der virtuellen klassen wird sichergestellt dass die Objekte folgende Mehtoden besitzen
class RenderAble {
public:
    RenderAble() = default;

    virtual ~RenderAble() = default;

    virtual void update(){std::cout << "base update"<< std::endl;};

    virtual bool init()=0; //durch diese null wird diese klasse du einer "pure virtual class" da diese methode nicht
    //ohne override aufgerufen werden kann

    virtual void render(){std::cout << "base render"<< std::endl;};
};


