//
// Created by Green on 2016/11/21.
//

#ifndef POSD_HW1_MYDOCUMENT_H
#define POSD_HW1_MYDOCUMENT_H


#include <fstream>
#include "Document.h"

class MyDocument : public Document{
private:
    std::ifstream file;

    virtual void openFile(const std::string name) override;

    virtual bool canOpenDocument(const std::string name) override;

    virtual std::string readFile() override;
};


#endif //POSD_HW1_MYDOCUMENT_H
