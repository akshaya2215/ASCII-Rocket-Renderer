#include "Rocket.h"

Rocket::Rocket()
{
    offset = 0;
     direction = 1;
}
void Rocket::draw(Renderer& screen)
{
    Point2D nose = {40, 2 + offset};

    Point2D leftTop = {34, 7 + offset};
    Point2D rightTop = {46, 7 + offset};

    Point2D leftBottom = {34, 20 + offset};
    Point2D rightBottom = {46, 20 + offset};

    Point2D leftWing = {23, 24 + offset};
    Point2D rightWing = {57, 24 + offset};

    Point2D leftEngine = {36, 24 + offset};
    Point2D rightEngine = {44, 24 + offset};

    Point2D exhaust = {40, 28 + offset};
    screen.drawLine(nose, leftTop, '/');
    screen.drawLine(nose, rightTop, '\\');

    screen.drawLine(leftTop, rightTop, '-');

    screen.drawLine(leftTop, leftBottom, '|');
    screen.drawLine(rightTop, rightBottom, '|');

    screen.drawLine(leftBottom, leftWing, '/');
    screen.drawLine(rightBottom, rightWing, '\\');

    screen.drawLine(leftWing, leftEngine, '_');
    screen.drawLine(leftEngine, rightEngine, '_');
    screen.drawLine(rightEngine, rightWing, '_');

    screen.drawLine(leftEngine, exhaust, '\\');
    screen.drawLine(rightEngine, exhaust, '/');

}
void Rocket::update()
{
    offset += direction;

    if (offset >= 5)
    {
        direction = -1;
    }

    if (offset <= 0)
    {
        direction = 1;
    }
}
void Rocket::draw3D(Renderer& screen)
{
    Point3D nose = {0.0f, 8.0f, 0.0f};

    Point3D leftTop = {-2.0f, 5.0f, 0.0f};
    Point3D rightTop = {2.0f, 5.0f, 0.0f};

    Point3D leftBottom = {-2.0f, -5.0f, 0.0f};
    Point3D rightBottom = {2.0f, -5.0f, 0.0f};

    Point3D leftWing = {-5.0f, -8.0f, 0.0f};
    Point3D rightWing = {5.0f, -8.0f, 0.0f};

    Point3D engineLeft = {-1.0f, -8.0f, 0.0f};
    Point3D engineRight = {1.0f, -8.0f, 0.0f};

    Point3D exhaust = {0.0f, -11.0f, 0.0f};
}