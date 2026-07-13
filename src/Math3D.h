#ifndef MATH3D_H
#define MATH3D_H

#include "Renderer.h"
#include <cmath>

struct Point3D
{
    float x;
    float y;
    float z;
};

class Math3D
{
public:
    static Point3D rotateX(Point3D p, float angle);
    static Point3D rotateY(Point3D p, float angle);
    static Point3D rotateZ(Point3D p, float angle);

    static Point2D project(Point3D p,
                           int screenWidth,
                           int screenHeight,
                           float distance);
};

#endif