#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float r, float g, float b);
    void draw() override;

    bool contains(float mx, float my) const override;

    void moveBy(float dx, float dy) override {
        x += dx;
        y += dy;
    }

    void resize(float scaleFactor) override;

};

#endif