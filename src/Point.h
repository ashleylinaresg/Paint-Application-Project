#ifndef POINT_H
#define POINT_H

#include "Shape.h"
#include <math.h>

class Point: public Shape {
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;

public:
    Point();
    Point(float x, float y);
    Point(float x, float y, float r, float g, float b);
    Point(float x, float y, float r, float g, float b, int size);

    void draw() override;

    float getX() const;
    float getY() const;
    float getR() const;
    float getG() const;
    float getB() const;
    int getSize() const;

    // Implement contains for Point
    bool contains(float mx, float my) const override {
        // A point "contains" another point if they are very close
        float distance = sqrt((mx - x) * (mx - x) + (my - y) * (my - y));
        return distance <= size;
    }

    void moveBy(float dx, float dy) override {
        x += dx;
        y += dy;
    }
};

#endif