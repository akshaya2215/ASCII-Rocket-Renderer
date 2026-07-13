#include "Renderer.h"
#include "Rocket.h"
#include "Cube.h"

#include <chrono>
#include <thread>

int main()
{
    Renderer screen(80,25);

    Rocket rocket;
    Cube cube;
    while(true)
    {
        screen.clear();

        rocket.update();

        cube.draw(screen);

        screen.display();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(80));
    }

    return 0;
}