//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_COMMAND_H
#define POSD_HW1_COMMAND_H

#include <string>

class Command{
protected:
    std::string _command;
    std::string _key;
    std::string _parentKey;
public:
    virtual bool needUndo() = 0;

    virtual void execute(std::string command) = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;

    virtual bool checkValid(std::string command) = 0;

    virtual Command* clone() = 0;

};

#endif //POSD_HW1_COMMAND_H
