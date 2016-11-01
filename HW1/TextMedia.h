//
// Created by ChangChun-wei on 2016/10/7.
//

#ifndef POSD_HW1_TEXTMEDIA_H
#define POSD_HW1_TEXTMEDIA_H


#include <vector>
#include "Media.h"
#include "Text.h"
class MediaVisitor;

class TextMedia : public Media{
public:
    TextMedia(Text *text);

    virtual void add(Media *shape) override;

    virtual void accept(MediaVisitor *visitor) override;

    virtual Text* getText();

private:
    Text *_text;
};


#endif //POSD_HW1_TEXTMEDIA_H
