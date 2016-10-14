#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle : public Shape{
public:
    Rectangle(double x, double y, double width, double height);

    double getX() const;
    double getY() const;
    double getWidth() const;
    double getHeight() const;

    double area() const;

    double perimeter() const;

    virtual void accept(MediaVisitor *visitor) override;

private:
    double x;
    double y;
    double width;
    double height;
};


#endif // RECTANGLE_H_INCLUDED
