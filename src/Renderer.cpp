#include "Renderer.h"

#include <iostream>
Renderer::Renderer(int w, int h)
{
    width = w;
    height = h;

    buffer.resize(height, std::string(width, ' '));
}
void Renderer::clear()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            buffer[y][x] = ' ';
        }
    }
}
void Renderer::drawPixel(int x, int y, char pixel)
{
    if (x >= 0 && x < width &&
        y >= 0 && y < height)
    {
        buffer[y][x] = pixel;
    }
}
void Renderer::display()
{
    std::cout << "\x1B[2J\x1B[H";

    for (const auto& row : buffer)
    {
        std::cout << row << '\n';
    }
}