#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;

public:
    Circle();
    Circle(float x, float y, float r, float g, float b);
    void draw() override;

    bool contains(float mx, float my) const override;
    
    // Override moveBy to move the circle
    void moveBy(float dx, float dy) override {
        x += dx;
        y += dy;
    }

    void resize(float scaleFactor) override;

};

#endif