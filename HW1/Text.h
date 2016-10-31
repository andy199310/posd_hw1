//
// Created by ChangChun-wei on 2016/10/7.
//

#ifndef POSD_HW1_TEXT_H
#define POSD_HW1_TEXT_H


#include <string>
#include "Rectangle.h"

class MediaVisitor;

class Text {
private:
    std::string text;
    Rectangle boundingBox;

public:
    Text(Rectangle boundingBox, std::string text);

    void accept(MediaVisitor* mediaVisitor);

    virtual std::string getText();

    virtual Rectangle getBoundingBox();

};


#endif //POSD_HW1_TEXT_H
