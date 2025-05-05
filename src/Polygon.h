#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape {
    float x;        // center x
    float y;        // center y
    int   sides;    // number of sides (>=3)
    float radius;   // distance from center to any vertex
    float r, g, b;  // color

public:
    Polygon();  
    // specify center, # of sides, radius, and color
    Polygon(float x, float y, int sides, float radius, float r, float g, float b);

    void draw() override;
};

#endif