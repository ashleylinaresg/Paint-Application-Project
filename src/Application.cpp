#include "Application.h"
#include "Enums.h"
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool        = toolbar->getTool();
    Color color      = selector->getColor();
    float  r         = color.getR();
    float  g         = color.getG();
    float  b         = color.getB();

    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, r, g, b, 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, 1, 1, 1, 14);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, r, g, b);
        canvas->redraw();
    }
    else if (tool == CIRCLE) {
        canvas->addCircle(mx, my, r, g, b);
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        // one‐click isosceles triangle
        canvas->addTriangle(mx, my, r, g, b);
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        // default to, say, a hexagon of radius 0.2
        int   sides  = 6;
        float radius = 0.2f;
        canvas->addPolygon(mx, my, sides, radius, r, g, b);
        canvas->redraw();
    }
}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    canvas->endScribble();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = selector->getColor();

    if (tool == PENCIL) {
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->updateScribble(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    }
}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    else if (action == UNDO) {
        canvas->undo();
        canvas->redraw();
    }
}

Application::Application() {
    window = new Window(100, 100, 400, 400, "Paint Application");

    toolbar = new Toolbar(0, 0, 50, 350);
    canvas = new Canvas(50, 0, 350, 350);
    selector = new ColorSelector(50, 350, 350, 50);
    selector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(selector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);

    window->show();
}