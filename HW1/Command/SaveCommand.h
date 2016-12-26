//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_SAVECOMMAND_H
#define POSD_HW1_SAVECOMMAND_H


#include "../Shell.h"
#include "../Application.h"
#include "Command.h"

class SaveCommand : public Command{
private:
    Application *_application;
public:
    virtual void execute(std::string command) override;

    virtual bool checkValid(std::string command) override;

    virtual bool needUndo() override;

    virtual void undo() override;

    virtual void redo() override;

    virtual Command *clone() override;

public:
    SaveCommand(Application *application);
};


#endif //POSD_HW1_SAVECOMMAND_H
