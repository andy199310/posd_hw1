//
// Created by ChangChun-wei on 2016/10/14.
//

#ifndef POSD_HW1_PERIMETERVISITOR_H
#define POSD_HW1_PERIMETERVISITOR_H

#include "MediaVisitor.h"

class PerimeterVisitor : public MediaVisitor{
public:
    virtual void visit(Rectangle *rectangle) override;

    virtual void visit(Circle *circle) override;

    virtual void visit(Triangle *triangle) override;

    virtual double getTotalPerimeter();

private:
    double totalPerimeter = 0;
};


#endif //POSD_HW1_PERIMETERVISITOR_H
