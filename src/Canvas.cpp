#include "Canvas.h"
#include "Circle.h"
#include "Scribble.h"
#include "Triangle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cstdlib>
#include <algorithm>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    curr = nullptr;
    selectedShape = nullptr; 
    lastMouseX = 0.0f;  
    lastMouseY = 0.0f;  
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
    redraw();
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

void Canvas::selectShape(float mx, float my) {
    for (auto& shape : shapes) {
        // Check if the shape contains the point (mx, my)
        if (shape->contains(mx, my)) {  
            selectedShape = shape;  // Set the clicked shape as the selected shape
            break;
        }
    }
}

void Canvas::moveShape(float dx, float dy) {
    if (selectedShape) {
        // Move the selected shape by dx and dy
        selectedShape->moveBy(dx, dy);
    }
}

void Canvas::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    if (selectedShape) {
        float dx = mx - lastMouseX;  // Calculate the change in x position
        float dy = my - lastMouseY;  // Calculate the change in y position

        // Move the selected shape
        selectedShape->moveBy(dx, dy);
        redraw();  // Redraw the canvas after moving the shape
    }

    lastMouseX = mx; 
    lastMouseY = my; 
}

void Canvas::resizeShape(float scaleFactor) {
    if (scaleFactor <= 0) {
        std::cerr << "Invalid scale factor: " << scaleFactor << std::endl;
        return;  // Prevent resizing if scale factor is invalid
    }
    if (selectedShape) {
        selectedShape->resize(scaleFactor);  // Call resize on the selected shape
        redraw();  // Redraw the canvas after resizing
    }
}

void Canvas::bringToFront() {
    if (selectedShape) {
        auto it = std::find(shapes.begin(), shapes.end(), selectedShape);
        if (it != shapes.end()) {
            shapes.erase(it);            // Remove the selected shape from the vector
            shapes.push_back(selectedShape);  // Add it to the end 
        }
    }
}

void Canvas::sendToBack() {
    if (selectedShape) {
        auto it = std::find(shapes.begin(), shapes.end(), selectedShape);
        if (it != shapes.end()) {
            shapes.erase(it);            // Remove the selected shape from the vector
            shapes.insert(shapes.begin(), selectedShape);  // Add it to the beginning
        }
    }
}