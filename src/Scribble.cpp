#include "Scribble.h"

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw(){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->draw();
    }
}

Scribble::~Scribble(){
    for (unsigned int i = 0; i < points.size(); i++){
        delete points[i];
    }
    points.clear();
}

void Scribble::resize(float scaleFactor) {
    for (auto& point : points) {
        point->resize(scaleFactor);  // Resize each point inside the scribble
    }
}