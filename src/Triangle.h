#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
    float x;      // center x
    float y;      // center y
    float width;  // full base width
    float height; // full height
    float r;      // red   component
    float g;      // green component
    float b;      // blue  component

public:
    Triangle();
    Triangle(float x, float y, float r, float g, float b);
    void draw() override;

    bool contains(float mx, float my) const override;

    // Override moveBy to move the triangle
    void moveBy(float dx, float dy) override {
        x += dx;
        y += dy;
    }

    void resize(float scaleFactor) override;
};

#endif // TRIANGLE_H
