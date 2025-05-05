#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath> 
//#include <algorithm>


Polygon::Polygon(float x, float y, float r, float g, float b, int sides) {
    this->x      = x;
    this->y      = y;
    this->sides  = sides;
    this->radius = 0.2f;
    this->r      = r;
    this->g      = g;
    this->b      = b;
}

void Polygon::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        
        for (int i = 0; i < sides; ++i) {
            float angle = 2.0f * M_PI * i / sides;
            float px = x + radius * cos(angle);
            float py = y + radius * sin(angle);
            glVertex2f(px, py);
        }
    glEnd();
}