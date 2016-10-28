//
// Created by Green on 2016/10/28.
//

#include <cstdio>
#include "CountingVisitor.h"

void CountingVisitor::visit(CompositeMedia *media) {
    printf("[%2d] Visiting '%s' (0x%p)\n", counting++, "CompositeMedia", media);
}

void CountingVisitor::visit(ShapeMedia *media) {
    printf("[%2d] Visiting '%s' (0x%p)\n", counting++, "ShapeMedia", media);
}

void CountingVisitor::visit(Rectangle *rectangle) {
    printf("[%2d] Visiting '%s' (0x%p)\n", counting++, "Rectangle", rectangle);
}

void CountingVisitor::visit(Circle *circle) {
    printf("[%2d] Visiting '%s' (0x%p)\n", counting++, "Circle", circle);
}

void CountingVisitor::visit(Triangle *triangle) {
    printf("[%2d] Visiting '%s' (0x%p)\n", counting++, "Triangle", triangle);
}

void CountingVisitor::visit(TextMedia *media) {
    printf("[%2d] Visiting '%s' (0x%p)\n", counting++, "TextMedia", media);
}

void CountingVisitor::visit(Text *text) {
    printf("[%2d] Visiting '%s' (0x%p)\n", counting++, "Text", text);
}
