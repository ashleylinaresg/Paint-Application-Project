#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble: public Shape {
    std::vector<Point*> points;

public:

    void addPoint(float x, float y, float r, float g, float b, int size);
    void draw() override;
    ~Scribble();

    void resize(float scaleFactor) override;

    // Implement contains for Scribble
    bool contains(float mx, float my) const override {
        for (const auto& point : points) {
            if (point->contains(mx, my)) {
                return true; 
            }
        }
        return false;  // No point containing (mx, my)
    }

    void moveBy(float dx, float dy) override {
        for (auto& point : points) {
            point->moveBy(dx, dy);  // Move each point inside the scribble
        }
    }
};
#endif