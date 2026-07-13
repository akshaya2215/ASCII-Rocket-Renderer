#include "Math3D.h"

Point3D Math3D::rotateX(Point3D p, float angle)
{
    Point3D result;

    float c = cos(angle);
    float s = sin(angle);

    result.x = p.x;
    result.y = p.y * c - p.z * s;
    result.z = p.y * s + p.z * c;

    return result;
}

Point3D Math3D::rotateY(Point3D p, float angle)
{
    Point3D result;

    float c = cos(angle);
    float s = sin(angle);

    result.x = p.x * c + p.z * s;
    result.y = p.y;
    result.z = -p.x * s + p.z * c;

    return result;
}

Point3D Math3D::rotateZ(Point3D p, float angle)
{
    Point3D result;

    float c = cos(angle);
    float s = sin(angle);

    result.x = p.x * c - p.y * s;
    result.y = p.x * s + p.y * c;
    result.z = p.z;

    return result;
}

Point2D Math3D::project(Point3D p,
                        int screenWidth,
                        int screenHeight,
                        float distance)
{
    Point2D result;

    float factor = distance / (distance + p.z);

    result.x = (int)(p.x * factor + screenWidth / 2);
    result.y = (int)(-p.y * factor + screenHeight / 2);

    return result;
}