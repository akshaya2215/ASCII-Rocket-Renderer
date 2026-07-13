#ifndef ROCKET_H
#define ROCKET_H

#include "Renderer.h"
#include "Math3D.h"

class Rocket
{
private:
    int offset;
    int direction;
    float angle;

public:
    Rocket();

    void update();

    void draw(Renderer& screen);

    void draw3D(Renderer& screen);
};

#endif