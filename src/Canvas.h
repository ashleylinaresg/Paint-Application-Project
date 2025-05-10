#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Shape.h"
#include "Scribble.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;

    Scribble* curr;
    Shape* selectedShape;  // Declare selectedShape var
    float lastMouseX;  // To store the last mouse X position
    float lastMouseY;  // To store the last mouse Y position
 
public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float x, float y, float r, float g, float b, int size);
    void addRectangle(float x, float y, float r, float g, float b);
    void addCircle(float x, float y, float r, float g, float b);
    void addPolygon(float x, float y, float r, float g, float b);
    void addTriangle(float x, float y, float r, float g, float b);

    void clear();
    void undo();
    void selectShape(float mx, float my);

    void startScribble();
    void updateScribble(float x, float y, float r, float g, float b, int size);
    void endScribble();

    void render();

    void onCanvasDrag(bobcat::Widget* sender, float mx, float my);

    void moveShape(float dx, float dy);  // Move selected shape
    void resizeShape(float scaleFactor);

    void bringToFront();
    void sendToBack();

};

#endif