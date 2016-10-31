//
// Created by Green on 2016/10/28.
//

#ifndef POSD_HW1_UTMEDIABUILDER_H
#define POSD_HW1_UTMEDIABUILDER_H

#define EPSILON 0.001

#include "../../cppunitlite/TestHarness.h"
#include "../DescriptionVisitor.h"
#include "../Rectangle.h"
#include "../Triangle.h"
#include "../ShapeMedia.h"
#include "../CompositeMedia.h"
#include "../MediaBuilder.h"

TEST(basic, MediaBuilder){
    MediaBuilder mediaBuilder;

    mediaBuilder.buildShapeMedia();
    mediaBuilder.buildCircle(0, 0, 5);
    mediaBuilder.levelDone();

    Media *media = mediaBuilder.getBaseShape();

    DescriptionVisitor descriptionVisitor;
    media->accept(&descriptionVisitor);

    CHECK("CompositeMedia(ShapeMedia(Circle(0,0,5)))" == descriptionVisitor.getDescription())
}

TEST(multipleLevel, MediaBuilder){
    MediaBuilder mediaBuilder;

    mediaBuilder.buildCompositeMedia();
    mediaBuilder.buildShapeMedia();
    mediaBuilder.buildRectangle(0, 0, 25, 20);
    mediaBuilder.levelDone();
    mediaBuilder.buildShapeMedia();
    mediaBuilder.buildRectangle(10, 0, 15, 5);
    mediaBuilder.buildCircle(12, 5, 2);
    mediaBuilder.levelDone();
    mediaBuilder.levelDone();
    mediaBuilder.buildShapeMedia();
    mediaBuilder.buildTriangle(0, 20, 16, 32, 25, 20);
    mediaBuilder.levelDone();



    Media *media = mediaBuilder.getBaseShape();

    DescriptionVisitor descriptionVisitor;
    media->accept(&descriptionVisitor);

    CHECK("CompositeMedia(CompositeMedia(ShapeMedia(Rectangle(0,0,25,20))ShapeMedia(Rectangle(10,0,15,5)Circle(12,5,2)))ShapeMedia(Triangle(0,20,16,32,25,20)))" == descriptionVisitor.getDescription())
}

#endif //POSD_HW1_UTMEDIABUILDER_H
