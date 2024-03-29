//
// Created by ChangChun-wei on 2016/10/13.
//

#ifndef POSD_HW1_AREAVISITOR_H
#define POSD_HW1_AREAVISITOR_H


#include "MediaVisitor.h"

class AreaVisitor : public MediaVisitor{
public:
    virtual void visit(CompositeMedia *media) override;

    virtual void visit(ShapeMedia *media) override;

    virtual void visit(Rectangle *rectangle) override;
    virtual void visit(Circle *circle) override;
    virtual void visit(Triangle *triangle) override;

    virtual void visit(TextMedia *media) override;

    virtual void visit(Text *text) override;


    virtual double getTotalArea(void);

private:
    double totalArea = 0;
};


#endif //POSD_HW1_AREAVISITOR_H
