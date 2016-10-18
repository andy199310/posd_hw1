//
// Created by ChangChun-wei on 2016/10/13.
//

#ifndef POSD_HW1_MEDIAVISITOR_H
#define POSD_HW1_MEDIAVISITOR_H

class CompositeMedia;

class ShapeMedia;

class Rectangle;
class Circle;
class Triangle;

class TextMedia;
class Text;

class MediaVisitor {
public:

    virtual void visit(CompositeMedia*) = 0;

    virtual void visit(ShapeMedia*) = 0;

    virtual void visit(Rectangle*) = 0;
    virtual void visit(Circle*) = 0;
    virtual void visit(Triangle*) = 0;

    virtual void visit(TextMedia*) = 0;

    virtual void visit(Text*) = 0;
};
#endif //POSD_HW1_MEDIAVISITOR_H
