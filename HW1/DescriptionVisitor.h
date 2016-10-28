//
// Created by ChangChun-wei on 2016/10/28.
//

#ifndef POSD_HW1_DESCRIPTIONVISITOR_H
#define POSD_HW1_DESCRIPTIONVISITOR_H


#include <string>
#include <stack>
#include "MediaVisitor.h"

class DescriptionVisitor : public MediaVisitor{
private:
    std::stack<std::string> descriptionStack;
public:
    virtual void visit(CompositeMedia *media) override;

    virtual void visit(ShapeMedia *media) override;

    virtual void visit(Rectangle *rectangle) override;

    virtual void visit(Circle *circle) override;

    virtual void visit(Triangle *triangle) override;

    virtual void visit(TextMedia *media) override;

    virtual void visit(Text *text) override;

    virtual std::string getDescription() const;
};


#endif //POSD_HW1_DESCRIPTIONVISITOR_H
