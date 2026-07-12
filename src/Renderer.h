#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>

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

    void drawLine(int x1, int y1, int x2, int y2, char pixel);
};

#endif