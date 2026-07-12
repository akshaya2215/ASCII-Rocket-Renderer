#include "Renderer.h"
#include <cmath>
#include <algorithm>
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
void Renderer::drawLine(int x1, int y1, int x2, int y2, char pixel)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = std::max(std::abs(dx), std::abs(dy));

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        drawPixel((int)std::round(x), (int)std::round(y), pixel);

        x += xIncrement;
        y += yIncrement;
    }
}