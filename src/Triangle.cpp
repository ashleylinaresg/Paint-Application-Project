// Triangle.cpp
#include "Triangle.h"
#include <GL/freeglut.h>
#include <cmath>

bool Triangle::contains(float mx, float my) const {
    // Vertices of the triangle
    float x1 = x;
    float y1 = y + height / 2;  // Top vertex
    float x2 = x - width / 2;
    float y2 = y - height / 2;  // Bottom-left vertex
    float x3 = x + width / 2;
    float y3 = y - height / 2;  // Bottom-right vertex

    // Area of the full triangle
    float area = 0.5f * (-y2 * x3 + y1 * (-x2 + x3) + x1 * (y2 - y3) + x2 * y3);

    // Areas of the smaller triangles formed with the point (mx, my)
    float area1 = 0.5f * (-y2 * mx + y1 * (-x2 + mx) + x1 * (y2 - my) + x2 * my);
    float area2 = 0.5f * (-y1 * mx + y3 * (-x1 + mx) + x2 * (y1 - my) + x1 * my);
    float area3 = 0.5f * (-y3 * mx + y2 * (-x1 + mx) + x3 * (y1 - my) + x2 * my);

    // If the sum of the areas of the smaller triangles is equal to the area of the full triangle,
    // the point (mx, my) is inside the triangle
    return (area == area1 + area2 + area3);
}

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

void Triangle::resize(float scaleFactor) {
    width *= scaleFactor;
    height *= scaleFactor;
}