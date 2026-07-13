#include "Rocket3D.h"

Rocket3D::Rocket3D()
{
    angle = 0.0f;

    // Nose
    vertices[0] = { 0.0f, 12.0f, 0.0f };

    // Body (front)
    vertices[1] = {-3.0f, 6.0f, 3.0f};
    vertices[2] = { 3.0f, 6.0f, 3.0f};
    vertices[3] = {-3.0f,-8.0f, 3.0f};
    vertices[4] = { 3.0f,-8.0f, 3.0f};

    // Body (back)
    vertices[5] = {-3.0f, 6.0f,-3.0f};
    vertices[6] = { 3.0f, 6.0f,-3.0f};
    vertices[7] = {-3.0f,-8.0f,-3.0f};
    vertices[8] = { 3.0f,-8.0f,-3.0f};

    // Exhaust
    vertices[9] = {0.0f,-12.0f,0.0f};
}
void Rocket3D::drawEdge(Renderer& screen, int a, int b)
{
    Point3D p1 = vertices[a];
    Point3D p2 = vertices[b];

    // Rotate around X
    p1 = Math3D::rotateX(p1, angle);
    p2 = Math3D::rotateX(p2, angle);

    // Rotate around Y
    p1 = Math3D::rotateY(p1, angle);
    p2 = Math3D::rotateY(p2, angle);

    // Move away from the camera
    p1.z += 30.0f;
    p2.z += 30.0f;

    // Project to 2D
    Point2D start = Math3D::project(p1, 80, 25, 80.0f);
    Point2D end   = Math3D::project(p2, 80, 25, 80.0f);

    // Draw edge
    screen.drawLine(start, end, '#');
}
void Rocket3D::draw(Renderer& screen)
{
    // Nose to front body
    drawEdge(screen, 0, 1);
    drawEdge(screen, 0, 2);

    // Nose to back body
    drawEdge(screen, 0, 5);
    drawEdge(screen, 0, 6);

    // Front face
    drawEdge(screen, 1, 2);
    drawEdge(screen, 2, 4);
    drawEdge(screen, 4, 3);
    drawEdge(screen, 3, 1);

    // Back face
    drawEdge(screen, 5, 6);
    drawEdge(screen, 6, 8);
    drawEdge(screen, 8, 7);
    drawEdge(screen, 7, 5);

    // Connect front and back
    drawEdge(screen, 1, 5);
    drawEdge(screen, 2, 6);
    drawEdge(screen, 3, 7);
    drawEdge(screen, 4, 8);

    // Exhaust
    drawEdge(screen, 3, 9);
    drawEdge(screen, 4, 9);
    drawEdge(screen, 7, 9);
    drawEdge(screen, 8, 9);
}
void Rocket3D::update()
{
    angle += 0.05f;

    if(angle > 6.28318f)   // 2 * PI
    {
        angle = 0.0f;
    }
}