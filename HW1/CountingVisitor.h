//
// Created by Green on 2016/10/28.
//

#ifndef POSD_HW1_COUNTINGVISITOR_H
#define POSD_HW1_COUNTINGVISITOR_H


#include "MediaVisitor.h"

class CountingVisitor : public MediaVisitor{
private:
    int counting = 0;
public:
    virtual void visit(CompositeMedia *media) override;

    virtual void visit(ShapeMedia *media) override;

    virtual void visit(Rectangle *rectangle) override;

    virtual void visit(Circle *circle) override;

    virtual void visit(Triangle *triangle) override;

    virtual void visit(TextMedia *media) override;

    virtual void visit(Text *text) override;
};


#endif //POSD_HW1_COUNTINGVISITOR_H
