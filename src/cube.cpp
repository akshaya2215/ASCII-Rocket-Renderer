#include "Cube.h"

Cube::Cube()
{
    angle = 0.0f;
    vertices[0] = {-8,-8,-8};
    vertices[1] = { 8,-8,-8};
    vertices[2] = { 8, 8,-8};
    vertices[3] = {-8, 8,-8};

    vertices[4] = {-8,-8, 8};
    vertices[5] = { 8,-8, 8};
    vertices[6] = { 8, 8, 8};
    vertices[7] = {-8, 8, 8};
}

void Cube::drawEdge(Renderer& screen, int a, int b)
{
   Point3D p1 = Math3D::rotateX(vertices[a], angle);
    p1 = Math3D::rotateY(p1, angle);
    p1.z += 30.0f;

    Point3D p2 = Math3D::rotateX(vertices[b], angle);
    p2 = Math3D::rotateY(p2, angle);
    p2.z += 30.0f;

    Point2D start = Math3D::project(p1, 80, 25, 80.0f);
    Point2D end   = Math3D::project(p2, 80, 25, 80.0f);

    screen.drawLine(start, end, '#');
}

void Cube::draw(Renderer& screen)
{
    // Front Face
    drawEdge(screen,0,1);
    drawEdge(screen,1,2);
    drawEdge(screen,2,3);
    drawEdge(screen,3,0);

    // Back Face
    drawEdge(screen,4,5);
    drawEdge(screen,5,6);
    drawEdge(screen,6,7);
    drawEdge(screen,7,4);

    // Connecting Edges
    drawEdge(screen,0,4);
    drawEdge(screen,1,5);
    drawEdge(screen,2,6);
    drawEdge(screen,3,7);
}
void Cube::update()
{
    angle += 0.08f;
}