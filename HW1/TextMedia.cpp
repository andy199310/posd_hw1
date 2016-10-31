//
// Created by ChangChun-wei on 2016/10/7.
//

#include "TextMedia.h"
#include "MediaVisitor.h"

void TextMedia::add(Text *shape) {
    textVector.push_back(shape);
}

void TextMedia::accept(MediaVisitor *visitor) {
    for(Text* text : textVector){
        text->accept(visitor);
    }
    visitor->visit(this);
}

void TextMedia::add(Media *shape) {
    throw "Cannot add Media with TextMedia";
}
