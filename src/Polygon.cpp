#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>  // for sinf(), cosf(), M_PI
#include <algorithm>

Polygon::Polygon() {
    x      = 0.0f;
    y      = 0.0f;
    sides  = 6;      // default to hexagon
    radius = 0.4f;
    r = g = b = 0.0f;
}

Polygon::Polygon(float x, float y, int sides, float radius, float r, float g, float b) {
    this->x      = x;
    this->y      = y;
    this->sides  = std::max(3, sides);  // ensure at least > 3
    this->radius = radius;
    this->r      = r;
    this->g      = g;
    this->b      = b;
}

void Polygon::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    // step around the circle in equal angles
    float angleStep = 2.0f * static_cast<float>(M_PI) / sides;
    for(int i = 0; i < sides; ++i) {
        float theta = i * angleStep;
        float vx = x + radius * cosf(theta);
        float vy = y + radius * sinf(theta);
        glVertex2f(vx, vy);
    }
    glEnd();
}