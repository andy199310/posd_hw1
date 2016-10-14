//
// Created by ChangChun-wei on 2016/10/13.
//

#ifndef POSD_HW1_AREAVISITOR_H
#define POSD_HW1_AREAVISITOR_H


#include "MediaVisitor.h"

class AreaVisitor : public MediaVisitor{
public:
    virtual void visit(Rectangle rectangle) override;

    virtual void visit(Circle circle) override;

    virtual void visit(Triangle triangle) override;

private:
    double totlaArea = 0;
};


#endif //POSD_HW1_AREAVISITOR_H
