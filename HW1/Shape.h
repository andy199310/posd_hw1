#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include "Media.h"
#include <string>
class MediaVisitor;

class Shape{
public:
    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual void accept(MediaVisitor*) = 0;

    virtual std::string toString() = 0;

};


#endif // SHAPE_H_INCLUDED
