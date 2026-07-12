#include "Renderer.h"

int main()
{
    Renderer screen(80,25);

    screen.clear();
    Point2D nose = {40,2};

    Point2D leftTop = {34,7};
    Point2D rightTop = {46,7};

    Point2D leftBottom = {33,20};
    Point2D rightBottom = {47,20};

    Point2D leftWing = {23,24};
    Point2D rightWing = {57,24};

    Point2D leftEngine = {36,24};
    Point2D rightEngine = {44,24};

    Point2D exhaust = {40,28};
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

    screen.display();

    return 0;
}