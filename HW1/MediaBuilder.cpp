//
// Created by Green on 2016/10/28.
//

#include "MediaBuilder.h"
#include "CompositeMedia.h"
#include "ShapeMedia.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

MediaBuilder::MediaBuilder() {
    //first must be compositeMedia (it rule by Green!
    baseMediaStack.push(new CompositeMedia());
}

void MediaBuilder::levelDone() {
    Media *media = baseMediaStack.top();
    baseMediaStack.pop();
    baseMediaStack.top()->add(media);
}

//First add to Stack. when we found that composite is finished, remove it from stack and add relation.
void MediaBuilder::buildCompositeMedia() {
    baseMediaStack.push(new CompositeMedia());
}

void MediaBuilder::buildShapeMedia() {
    baseMediaStack.push(new ShapeMedia());
}

void MediaBuilder::buildRectangle(double x, double y, double width, double height) {
    ShapeMedia *shapeMedia = dynamic_cast<ShapeMedia*>(baseMediaStack.top());
    shapeMedia->add(new Rectangle(x, y, width, height));
}

void MediaBuilder::buildCircle(double centerX, double centerY, double radius) {
    ShapeMedia *shapeMedia = dynamic_cast<ShapeMedia*>(baseMediaStack.top());
    shapeMedia->add(new Circle(centerX, centerY, radius));
}

void MediaBuilder::buildTriangle(double point1X, double point1Y, double point2X, double point2Y, double point3X, double point3Y) {
    ShapeMedia *shapeMedia = dynamic_cast<ShapeMedia*>(baseMediaStack.top());
    shapeMedia->add(new Triangle(point1X, point1Y, point2X, point2Y, point3X, point3Y));
}

Media *MediaBuilder::getBaseShape() {
    if(baseMediaStack.size() != 1){
        throw "There is error in building level";
    }
    return baseMediaStack.top();
}
