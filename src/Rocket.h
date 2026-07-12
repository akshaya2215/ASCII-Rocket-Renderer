#ifndef ROCKET_H
#define ROCKET_H

#include "Renderer.h"

class Rocket
{
private:
    int offset;
    int direction;

public:
    Rocket();

    void update();

    void draw(Renderer& screen);
};

#endif