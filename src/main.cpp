#include "Renderer.h"

int main()
{
    Renderer screen(80,25);

    screen.clear();

    screen.drawLine(5,5,70,5,'-');      // Horizontal

    screen.drawLine(10,2,10,20,'|');    // Vertical

    screen.drawLine(5,20,70,2,'*');     // Diagonal

    screen.display();

    return 0;
}