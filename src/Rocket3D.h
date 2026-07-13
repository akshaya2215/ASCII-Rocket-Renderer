#ifndef ROCKET3D_H
#define ROCKET3D_H

#include "Renderer.h"
#include "Math3D.h"

class Rocket3D
{
private:

    static const int VERTEX_COUNT = 48;
    static const int EDGE_COUNT = 72;

    Point3D vertices[VERTEX_COUNT];

    int edges[EDGE_COUNT][2];

    float angle;

    void drawEdge(Renderer& screen,int a,int b);

public:

    Rocket3D();

    void update();

    void draw(Renderer& screen);
};

#endif