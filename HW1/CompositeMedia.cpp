//
// Created by Green on 2016/10/4.
//

#include <iostream>
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

bool CompositeMedia::remove(Media *removeMedia) {
    int index = 0;
    for(Media *media : mediaVector){
        if(media == removeMedia){
            mediaVector.erase(mediaVector.begin() + index);
            return true;
        }
        if(media->remove(removeMedia)){

            return true;
        }
        index++;
    }
    return false;
}

