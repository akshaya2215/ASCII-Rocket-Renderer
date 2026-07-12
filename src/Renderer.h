#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
struct Point2D
{
    int x;
    int y;
};

class Renderer
{
private:
    int width;
    int height;
    std::vector<std::string> buffer;

public:
    Renderer(int w, int h);

    void clear();

    void display();

    void drawPixel(int x, int y, char pixel);

    void drawLine(Point2D start,
              Point2D end,
              char pixel);
};

#endif