#include "Canvas.h"
#include "Circle.h"
#include "Scribble.h"
#include "Triangle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cstdlib>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    curr = nullptr;
}

void Canvas::addPoint(float x, float y, float r, float g, float b, int size) {
    shapes.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::addRectangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Rectangle(x, y, r, g, b));
}

void Canvas::addCircle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Circle(x, y, r, g, b));
}

void Canvas::addPolygon(float x, float y, float r, float g, float b) {
    //std::cout << "Adding polygon at (" << x << ", " << y << ") with radius 0.5\n";  // Debugging output
    shapes.push_back(new Polygon(x, y, r, g, b));
}



void Canvas::addTriangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Triangle(x, y, r, g, b));
}

void Canvas::clear() {
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
}

void Canvas::undo(){
    if (shapes.size() > 0){
        delete shapes[shapes.size() - 1];
        shapes.pop_back();
    }
}

void Canvas::render() {
    glClear(GL_COLOR_BUFFER_BIT); // screen clear before render
    for (unsigned int i = 0 ; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    if (curr){
        curr->draw();
    }
    glFlush(); 
}

void Canvas::startScribble(){
    curr = new Scribble();
}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size){
    if (curr){
        curr->addPoint(x, y, r, g, b, size);
    }
}

void Canvas::endScribble(){
    if (curr){
        shapes.push_back(curr);
        curr = nullptr;
    }
}

// void Canvas::selectShape(float mx, float my) {
//     for (auto& shape : shapes) {
//         if (shape->contains(mx, my)) {  // Assuming you have a 'contains' method in your shapes to check if the point is inside the shape
//             selectedShape = shape;  // Set the clicked shape as the selected shape
//             break;
//         }
//     }
// }
