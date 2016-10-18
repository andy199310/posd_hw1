//
// Created by ChangChun-wei on 2016/10/7.
//

#ifndef POSD_HW1_TEXT_H
#define POSD_HW1_TEXT_H


#include <string>
class MediaVisitor;

class Text {
public:
    void accept(MediaVisitor*);

    std::string name;
};


#endif //POSD_HW1_TEXT_H
