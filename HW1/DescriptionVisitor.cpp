//
// Created by ChangChun-wei on 2016/10/28.
//

#include <sstream>
#include "DescriptionVisitor.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeMedia.h"
#include "CompositeMedia.h"

void DescriptionVisitor::visit(CompositeMedia *media) {
    std::stringstream stringStream;
    stringStream << "combo(";
    std::stack<std::string> reverseStack;
    for(int i=0; i<media->size(); i++){
        reverseStack.push(descriptionStack.top());
        descriptionStack.pop();
    }
    while(reverseStack.size() > 0){
        stringStream << reverseStack.top();
        reverseStack.pop();
    }
    stringStream << ")";
    descriptionStack.push(stringStream.str());
}

void DescriptionVisitor::visit(ShapeMedia *media) {
    // nothing
}

void DescriptionVisitor::visit(Rectangle *rectangle) {
    descriptionStack.push(rectangle->toString());
}

void DescriptionVisitor::visit(Circle *circle) {
    descriptionStack.push(circle->toString());
}

void DescriptionVisitor::visit(Triangle *triangle) {
    descriptionStack.push(triangle->toString());
}

void DescriptionVisitor::visit(TextMedia *media) {
    // nothing
}

void DescriptionVisitor::visit(Text *text) {
    //TODO text
    descriptionStack.push("Text");
}

std::string DescriptionVisitor::getDescription() const {
    return descriptionStack.top();
}
