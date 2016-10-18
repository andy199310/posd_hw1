//
// Created by Green on 2016/10/4.
//

#include "CompositeMedia.h"
#include "MediaVisitor.h"

CompositeMedia::CompositeMedia() {

}

void CompositeMedia::add(Media * media) {
    mediaVector.push_back(media);
}

int CompositeMedia::size() const{
    return mediaVector.size();
}

Media* CompositeMedia::at(unsigned int index) const{
    return mediaVector.at(index);
}

void CompositeMedia::remove(unsigned int index) {
    mediaVector.erase(mediaVector.begin() + index);
}

void CompositeMedia::accept(MediaVisitor* visitor) {
    for(Media *media : mediaVector){
        media->accept(visitor);
    }
    visitor->visit(this);
}

