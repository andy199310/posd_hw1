//
// Created by Green on 2016/12/5.
//

#include <sstream>
#include "DescriptionNameVisitor.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeMedia.h"
#include "CompositeMedia.h"
#include "Application.h"

void DescriptionNameVisitor::visit(CompositeMedia *media) {
    std::stringstream stringStream;
    stringStream << _application->getNameByMedia(media) << "{";
    std::stack<std::string> reverseStack;
    for(int i=0; i<media->size(); i++){
        reverseStack.push(descriptionNameStack.top());
        descriptionNameStack.pop();
    }
    while(reverseStack.size() > 0){
        stringStream << reverseStack.top();
        reverseStack.pop();
    }
    stringStream << "}";
    descriptionNameStack.push(stringStream.str());
}

void DescriptionNameVisitor::visit(ShapeMedia *media) {
    // nothing
    std::stringstream stringStream;
    stringStream << _application->getNameByMedia(media) << " ";
    descriptionNameStack.push(stringStream.str());
}

void DescriptionNameVisitor::visit(Rectangle *rectangle) {


}

void DescriptionNameVisitor::visit(Circle *circle) {
//    descriptionNameStack.push(circle->toString());
}

void DescriptionNameVisitor::visit(Triangle *triangle) {
//    descriptionNameStack.push(triangle->toString());
}

void DescriptionNameVisitor::visit(TextMedia *media) {
    // nothing
}

void DescriptionNameVisitor::visit(Text *text) {
    //TODO text
    descriptionNameStack.push("Text");
}

std::string DescriptionNameVisitor::getDescription() const {
    return descriptionNameStack.top();
}

DescriptionNameVisitor::DescriptionNameVisitor(Application *application):_application(application) {

}
