#include "Cube.h"

Cube::Cube()
{
    vertices[0] = {-5, -5, -5};
    vertices[1] = { 5, -5, -5};
    vertices[2] = { 5,  5, -5};
    vertices[3] = {-5,  5, -5};

    vertices[4] = {-5, -5,  5};
    vertices[5] = { 5, -5,  5};
    vertices[6] = { 5,  5,  5};
    vertices[7] = {-5,  5,  5};
}

void Cube::drawEdge(Renderer& screen, int a, int b)
{
    Point2D p1 = Math3D::project(vertices[a], 80, 25, 25.0f);
    Point2D p2 = Math3D::project(vertices[b], 80, 25, 25.0f);

    screen.drawLine(p1, p2, '#');
}

void Cube::draw(Renderer& screen)
{
    // Front
    drawEdge(screen,0,1);
    drawEdge(screen,1,2);
    drawEdge(screen,2,3);
    drawEdge(screen,3,0);

    // Back
    drawEdge(screen,4,5);
    drawEdge(screen,5,6);
    drawEdge(screen,6,7);
    drawEdge(screen,7,4);

    // Connections
    drawEdge(screen,0,4);
    drawEdge(screen,1,5);
    drawEdge(screen,2,6);
    drawEdge(screen,3,7);
}