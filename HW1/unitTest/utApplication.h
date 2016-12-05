//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTAPPLICATION_H
#define POSD_HW1_UTAPPLICATION_H

#define EPSILON 0.001

#include "../CompositeMedia.h"
#include "../Application.h"
#include "../../cppunitlite/TestHarness.h"

TEST(getMediaByNameNotFound, Application){
    Application *application = new Application();
    if(application->getMediaByName("key") == nullptr){
        CHECK(true);
    }else{
        FAIL("Should not be here");
    }
}

TEST(addMedia, Application){
    Application *application = new Application();
    if(application->addMedia("key", new CompositeMedia())){
        CHECK(true);
    }else{
        FAIL("Should not be here")
    }
}

TEST(addMediaDuplicate, Application){
    Application *application = new Application();
    application->addMedia("key", new CompositeMedia());
    if(application->addMedia("key", new CompositeMedia())){
        FAIL("Should not be here")
    }else{
        CHECK(true);
    }
}

TEST(getMediaByNameFound, Application){
    Application *application = new Application();
    application->addMedia("key", new CompositeMedia());
    if(application->getMediaByName("key") == nullptr){
        FAIL("Should not be here");
    }else{
        CHECK(true);
    }
}

#endif //POSD_HW1_UTAPPLICATION_H
