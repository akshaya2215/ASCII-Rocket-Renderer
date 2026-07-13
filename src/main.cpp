#include "Renderer.h"
#include "Rocket.h"
#include "Cube.h"
#include "Rocket3D.h"

#include <chrono>
#include <thread>

int main()
{
    Renderer screen(80,25);

    Rocket rocket;
    Cube cube;
    Rocket3D rocket3d;
    while(true)
    {
        screen.clear();
        rocket3d.update();
        rocket3d.draw(screen);
        screen.display();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(50));
    }

    return 0;
}