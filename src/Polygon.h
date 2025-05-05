#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <FL/Fl.H>
#include <vector>

class Polygon : public Shape {
    float x;        // center x
    float y;        // center y
    int sides;      // number of sides (>=3)
    float radius;   // distance from center to any vertex
    float r, g, b;  // color

public:
    Polygon();  
    // specify center, # of sides, radius, and color
    Polygon(float x, float y, float r, float g, float b, int sides = 5); // constructor
    void draw();

};

#endif