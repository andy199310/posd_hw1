//
// Created by Green on 2016/10/28.
//

#include <iostream>
#include "MediaBuilder.h"
#include "CompositeMedia.h"
#include "ShapeMedia.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

MediaBuilder::MediaBuilder() {
    //first must be compositeMedia (it rule by Green!
//    baseMediaStack.push(new CompositeMedia());
    childrenCountStack.push(0);
}

void MediaBuilder::levelDone() {
    std::stack<Media*> reverseStack;
    int childrenCount = childrenCountStack.top();
    childrenCountStack.pop();
    for(int i=0; i<childrenCount; i++){
        if(baseMediaStack.size() > 1){
            Media *media = baseMediaStack.top();
            reverseStack.push(media);
            baseMediaStack.pop();
        }
    }
    while(!reverseStack.empty()){
        baseMediaStack.top()->add(reverseStack.top());
        reverseStack.pop();
    }
    childrenCountStack.top() += 1;
}

//First add to Stack. when we found that composite is finished, remove it from stack and add relation.
void MediaBuilder::buildCompositeMedia() {
    baseMediaStack.push(new CompositeMedia());
    childrenCountStack.push(0);
}

void MediaBuilder::buildShapeMedia() {
//    baseMediaStack.push(new ShapeMedia());
}

void MediaBuilder::buildRectangle(double x, double y, double width, double height) {
    baseMediaStack.push(new ShapeMedia(new Rectangle(x, y, width, height)));
    childrenCountStack.top() += 1;
}

void MediaBuilder::buildCircle(double centerX, double centerY, double radius) {
    baseMediaStack.push(new ShapeMedia(new Circle(centerX, centerY, radius)));
    childrenCountStack.top() += 1;
}

void MediaBuilder::buildTriangle(double point1X, double point1Y, double point2X, double point2Y, double point3X, double point3Y) {
    baseMediaStack.push(new ShapeMedia(new Triangle(point1X, point1Y, point2X, point2Y, point3X, point3Y)));
    childrenCountStack.top() += 1;
}

Media *MediaBuilder::getBaseShape() {
    if(baseMediaStack.size() != 1){
        throw "There is error in building level";
    }
    return baseMediaStack.top();
}
