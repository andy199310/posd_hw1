#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include "Media.h"
class MediaVisitor;

class Shape{
public:
    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual void accept(MediaVisitor*) = 0;

};


#endif // SHAPE_H_INCLUDED
