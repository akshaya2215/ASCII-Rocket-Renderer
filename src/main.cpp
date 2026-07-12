#include "Renderer.h"

int main()
{
    Renderer screen(80,25);

    screen.clear();
    Point2D A = {5,5};
    Point2D B = {70,5};

    Point2D C = {10,2};
    Point2D D = {10,20};

    Point2D E = {5,20};
    Point2D F = {70,2};
    screen.drawLine(A,B,'-');

    screen.drawLine(C,D,'|');

    screen.drawLine(E,F,'*');
   

    screen.display();

    return 0;
}