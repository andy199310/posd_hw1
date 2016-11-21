//
// Created by Green on 2016/11/21.
//

#ifndef POSD_HW1_UTMEDIADIRECTOR_H
#define POSD_HW1_UTMEDIADIRECTOR_H

#define EPSILON 0.001

#include "../../cppunitlite/TestHarness.h"
#include "../MediaDirector.h"
#include "../MediaBuilder.h"
#include "../MyDocument.h"
#include "../DescriptionVisitor.h"

TEST(basicCombo, MediaDirector){
    MediaBuilder mediaBuilder;
    MediaDirector mediaDirector(&mediaBuilder);
    DescriptionVisitor descriptionVisitor;
    std::string testString = "combo()";

    mediaDirector.construct(testString);
    mediaBuilder.getBaseShape()->accept(&descriptionVisitor);

    CHECK(testString == descriptionVisitor.getDescription());
}

TEST(basicRectangle, MediaDirector){
    MediaBuilder mediaBuilder;
    MediaDirector mediaDirector(&mediaBuilder);
    DescriptionVisitor descriptionVisitor;
    std::string testString = "r(0 0 100.1 200.2) ";

    mediaDirector.construct(testString);
    mediaBuilder.getBaseShape()->accept(&descriptionVisitor);

    CHECK(testString == descriptionVisitor.getDescription());
}

TEST(basicCircle, MediaDirector){
    MediaBuilder mediaBuilder;
    MediaDirector mediaDirector(&mediaBuilder);
    DescriptionVisitor descriptionVisitor;
    std::string testString = "c(0 0 54.66) ";

    mediaDirector.construct(testString);
    mediaBuilder.getBaseShape()->accept(&descriptionVisitor);

    CHECK(testString == descriptionVisitor.getDescription());
}

TEST(basicTriangle, MediaDirector){
    MediaBuilder mediaBuilder;
    MediaDirector mediaDirector(&mediaBuilder);
    DescriptionVisitor descriptionVisitor;
    std::string testString = "t(0 0 54.66 2 3 4) ";

    mediaDirector.construct(testString);
    mediaBuilder.getBaseShape()->accept(&descriptionVisitor);

    CHECK(testString == descriptionVisitor.getDescription());
}

TEST(basicTwoLevel, MediaDirector){
    MediaBuilder mediaBuilder;
    MediaDirector mediaDirector(&mediaBuilder);
    DescriptionVisitor descriptionVisitor;
    std::string testString = "combo(r(0 0 100.1 200.2) )";

    mediaDirector.construct(testString);
    mediaBuilder.getBaseShape()->accept(&descriptionVisitor);

    CHECK(testString == descriptionVisitor.getDescription());
}

TEST(basicThreeLevel, MediaDirector){
    MediaBuilder mediaBuilder;
    MediaDirector mediaDirector(&mediaBuilder);
    DescriptionVisitor descriptionVisitor;
    std::string testString = "combo(combo(r(0 0 100.1 200.2) ))";

    mediaDirector.construct(testString);
    mediaBuilder.getBaseShape()->accept(&descriptionVisitor);

    CHECK(testString == descriptionVisitor.getDescription());
}


TEST(complexHomework, MediaDirector){
    MediaBuilder mediaBuilder;
    MediaDirector mediaDirector(&mediaBuilder);
    MyDocument myDocument;
    Media *baseMedia;

    try{
        std::string documentString = myDocument.openDocument("myShape.txt");

        mediaDirector.construct(documentString);

        baseMedia = mediaBuilder.getBaseShape();

        DescriptionVisitor descriptionVisitor;
        baseMedia->accept(&descriptionVisitor);

        CHECK(descriptionVisitor.getDescription() == "combo(r(0 0 3 2) c(0 0 5) combo(r(0 0 5 4) c(0 0 10) )combo(r(0 1 8 7) c(0 1 10) ))")
    }catch(std::string message){
        FAIL("Cannot be here!");
    }
}

#endif //POSD_HW1_UTMEDIADIRECTOR_H
