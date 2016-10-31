//
// Created by ChangChun-wei on 2016/10/7.
//

#include "Text.h"
#include "MediaVisitor.h"

void Text::accept(MediaVisitor * mediaVisitor) {
    mediaVisitor->visit(this);
}

Text::Text(Rectangle boundingBox, std::string text) : boundingBox(boundingBox), text(text){

}

std::string Text::getText() {
    return text;
}

Rectangle Text::getBoundingBox() {
    return boundingBox;
}


