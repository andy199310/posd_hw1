//
// Created by Green on 2016/11/21.
//

#ifndef POSD_HW1_DOCUMENT_H
#define POSD_HW1_DOCUMENT_H

#include <string>

class Document{
public:
    std::string openDocument(const std::string name){
        if(!canOpenDocument(name)){
            throw std::string("File is not existed.");
        }
        openFile(name);
        return readFile();
    }

protected:
    virtual void openFile(const std::string name) = 0;
    virtual bool canOpenDocument(const std::string name) = 0;
    virtual std::string readFile() = 0;
};

#endif //POSD_HW1_DOCUMENT_H
