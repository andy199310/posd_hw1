//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_DESCIPTIONNAMEVISITOR_H
#define POSD_HW1_DESCIPTIONNAMEVISITOR_H


#include <string>
#include <stack>
#include "MediaVisitor.h"
#include "Application.h"

class DescriptionNameVisitor : public MediaVisitor{
private:
    std::stack<std::string> descriptionNameStack;
    Application *_application;
public:
    DescriptionNameVisitor(Application* application);
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


#endif //POSD_HW1_DESCIPTIONNAMEVISITOR_H
