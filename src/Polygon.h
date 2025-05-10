#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <FL/Fl.H>
#include <vector>

class Polygon : public Shape {
    float x;        
    float y;        
    int sides;      
    float radius;   
    float r, g, b;  

public:
    Polygon();  
    // specify center, # of sides, radius, and color
    Polygon(float x, float y, float r, float g, float b, int sides = 5); // constructor
    void draw() override;

    bool contains(float mx, float my) const override;

    void moveBy(float dx, float dy) override {
        x += dx;
        y += dy;
    }

    void resize(float scaleFactor) override;

};

#endif