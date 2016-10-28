#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Shape.h"

class Circle : public Shape{
public:
    Circle(double centerX, double centerY, double radius);

    double getCenterX() const;
    double getCenterY() const;
    double getRadius() const;

    double area() const;

    double perimeter() const;

    virtual void accept(MediaVisitor *visitor) override;

    virtual std::string toString() override;

private:
    double centerX;
    double centerY;
    double radius;
};


#endif // CIRCLE_H_INCLUDED
