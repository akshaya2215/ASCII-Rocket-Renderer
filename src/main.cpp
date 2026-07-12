#include "Renderer.h"

int main()
{
    Renderer screen(60, 20);

    screen.clear();

    screen.drawPixel(30,10,'@');

    screen.display();

    return 0;
}