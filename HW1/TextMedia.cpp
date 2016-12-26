//
// Created by ChangChun-wei on 2016/10/7.
//

#include "TextMedia.h"
#include "MediaVisitor.h"


void TextMedia::accept(MediaVisitor *visitor) {
    _text->accept(visitor);
    visitor->visit(this);
}

void TextMedia::add(Media *shape) {
    throw "Cannot add Media with TextMedia";
}

TextMedia::TextMedia(Text *text) {
    _text = text;
}

Text *TextMedia::getText() {
    return _text;
}

bool TextMedia::remove(Media *removeMedia) {
    return false;
}

bool TextMedia::haveChild(Media *media) {
    return false;
}
