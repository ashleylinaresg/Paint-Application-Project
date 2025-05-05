// Triangle.cpp
#include "Triangle.h"
#include <GL/freeglut.h>

Triangle::Triangle() {
    x = 0.0f;
    y = 0.0f;
    width = 0.4f;
    height = 0.4f;
    r = 0.0f;
    g = 0.0f;
    b = 0.0f;
}

Triangle::Triangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    width  = 0.4f;
    height = 0.4f;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::draw() {
    // half‐extents
    float hw = width  / 2.0f;
    float hh = height / 2.0f;

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        // top vertex
        glVertex2f(x,       y + hh);
        // bottom‐left
        glVertex2f(x - hw,  y - hh);
        // bottom‐right
        glVertex2f(x + hw,  y - hh);
    glEnd();
}
