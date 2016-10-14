//
// Created by ChangChun-wei on 2016/10/7.
//

#include "TextMedia.h"

void TextMedia::add(Text *shape) {
    textVector.push_back(shape);
}

void TextMedia::accept(MediaVisitor *visitor) {
//TODO
}
