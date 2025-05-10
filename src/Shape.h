#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>

class Shape{

public:
    virtual void draw() = 0;

    virtual bool contains(float mx, float my) const = 0;
    virtual void moveBy(float dx, float dy) = 0;
    virtual void resize(float scaleFactor) = 0;

    virtual ~Shape(){}
};

#endif