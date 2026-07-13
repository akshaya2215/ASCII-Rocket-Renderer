#include "Rocket3D.h"

Rocket3D::Rocket3D()
{
    angle = 0.0f;

    // ===== Nose =====
    vertices[0] = {0,15,0};

    // ===== Upper Ring =====
    vertices[1] = {-2,12, 2};
    vertices[2] = { 2,12, 2};
    vertices[3] = { 2,12,-2};
    vertices[4] = {-2,12,-2};

    // ===== Middle Ring =====
    vertices[5] = {-2,4,2};
    vertices[6] = { 2,4,2};
    vertices[7] = { 2,4,-2};
    vertices[8] = {-2,4,-2};

    // ===== Bottom Ring =====
    vertices[9]  = {-2,-8,2};
    vertices[10] = { 2,-8,2};
    vertices[11] = { 2,-8,-2};
    vertices[12] = {-2,-8,-2};

    // ===== Engine =====
    vertices[13] = {-1,-12,1};
    vertices[14] = { 1,-12,1};
    vertices[15] = { 1,-12,-1};
    vertices[16] = {-1,-12,-1};

    vertices[17] = {0,-15,0};

    // ===== Left Fin =====
    vertices[18] = {-2,-6,2};
    vertices[19] = {-6,-10,2};
    vertices[20] = {-2,-12,2};

    // ===== Right Fin =====
    vertices[21] = {2,-6,2};
    vertices[22] = {6,-10,2};
    vertices[23] = {2,-12,2};

    // ===== Back Left Fin =====
    vertices[24] = {-2,-6,-2};
    vertices[25] = {-6,-10,-2};
    vertices[26] = {-2,-12,-2};

    // ===== Back Right Fin =====
    vertices[27] = {2,-6,-2};
    vertices[28] = {6,-10,-2};
    vertices[29] = {2,-12,-2};

    // Remaining vertices
    for(int i=30;i<VERTEX_COUNT;i++)
    {
        vertices[i]={0,0,0};
    }
        // ===== Edge List =====
    int tempEdges[][2] =
    {
        // Nose to Upper Ring
        {0,1},{0,2},{0,3},{0,4},

        // Upper Ring
        {1,2},{2,3},{3,4},{4,1},

        // Upper Ring -> Middle Ring
        {1,5},{2,6},{3,7},{4,8},

        // Middle Ring
        {5,6},{6,7},{7,8},{8,5},

        // Middle Ring -> Bottom Ring
        {5,9},{6,10},{7,11},{8,12},

        // Bottom Ring
        {9,10},{10,11},{11,12},{12,9},

        // Engine
        {9,13},{10,14},{11,15},{12,16},
        {13,14},{14,15},{15,16},{16,13},
        {13,17},{14,17},{15,17},{16,17},

        // Left Fin
        {9,18},{18,19},{19,20},{20,9},

        // Right Fin
        {10,21},{21,22},{22,23},{23,10},

        // Back Left Fin
        {12,24},{24,25},{25,26},{26,12},

        // Back Right Fin
        {11,27},{27,28},{28,29},{29,11}
    };

    int edgeCount = sizeof(tempEdges) / sizeof(tempEdges[0]);

    for(int i = 0; i < edgeCount; i++)
    {
        edges[i][0] = tempEdges[i][0];
        edges[i][1] = tempEdges[i][1];
    }

    for(int i = edgeCount; i < EDGE_COUNT; i++)
    {
        edges[i][0] = -1;
        edges[i][1] = -1;
    }

}   // <-- Constructor ends here
void Rocket3D::drawEdge(Renderer& screen, int a, int b)
{
    // Ignore invalid edges
    if(a < 0 || b < 0)
        return;

    // Get the two vertices
    Point3D p1 = vertices[a];
    Point3D p2 = vertices[b];

    // Rotate ONLY around the Y-axis (like Earth)
    p1 = Math3D::rotateY(p1, angle);
    p2 = Math3D::rotateY(p2, angle);

    // Move the rocket away from the camera
    p1.z += 45.0f;
    p2.z += 45.0f;

    // Convert from 3D to 2D
    Point2D start = Math3D::project(
        p1,
        80,
        25,
        90.0f
    );

    Point2D end = Math3D::project(
        p2,
        80,
        25,
        90.0f
    );

    // Draw the edge
    screen.drawLine(start, end, '#');
}
void Rocket3D::draw(Renderer& screen)
{
    for(int i = 0; i < EDGE_COUNT; i++)
    {
        // Skip unused edges
        if(edges[i][0] == -1 || edges[i][1] == -1)
            continue;

        drawEdge(
            screen,
            edges[i][0],
            edges[i][1]
        );
    }
}
void Rocket3D::update()
{
    // Smooth rotation like a display model
    angle += 0.015f;

    // Keep the angle between 0 and 2π
    if(angle >= 6.283185f)
    {
        angle = 0.0f;
    }
}