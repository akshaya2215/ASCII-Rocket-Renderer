#ifndef ROCKET3D_H
#define ROCKET3D_H

#include "Renderer.h"
#include "Math3D.h"

class Rocket3D
{
private:

    Point3D vertices[10];

    float angle;

    void drawEdge(Renderer& screen,int a,int b);

public:

    Rocket3D();

    void update();

    void draw(Renderer& screen);
};

#endif