#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

class Shape{
public:
    virtual double area() const = 0;

    virtual double perimeter() const = 0;
};


#endif // SHAPE_H_INCLUDED
