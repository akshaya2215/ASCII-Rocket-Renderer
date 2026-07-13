#ifndef CUBE_H
#define CUBE_H

#include "Renderer.h"
#include "Math3D.h"

class Cube
{
private:
    Point3D vertices[8];

public:
    Cube();

    void draw(Renderer& screen);

private:
    void drawEdge(Renderer& screen, int a, int b);
};

#endif