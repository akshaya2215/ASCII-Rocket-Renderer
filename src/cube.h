#ifndef CUBE_H
#define CUBE_H

#include "Renderer.h"
#include "Math3D.h"

class Cube
{
private:
    Point3D vertices[8];
    float angle;

    void drawEdge(Renderer& screen, int a, int b);

public:
    Cube();

    void update();

    void draw(Renderer& screen);
};

#endif