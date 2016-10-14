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
    void add(Text *shape);

    int size() const;

    virtual void accept(MediaVisitor *visitor) override;

private:
    std::vector<Text *> textVector;
};


#endif //POSD_HW1_TEXTMEDIA_H
