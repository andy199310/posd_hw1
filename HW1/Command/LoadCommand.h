//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_LOADCOMMAND_H
#define POSD_HW1_LOADCOMMAND_H

#include "../Application.h"
#include "Command.h"

class LoadCommand : public Command{
private:
    Application *_application;
    void addToApplication(Media* media, std::string *string);
public:
    LoadCommand(Application *application);

    virtual void execute(std::string command) override;

    virtual bool checkValid(std::string command) override;

    virtual bool needUndo() override;

    virtual void undo() override;

    virtual void redo() override;

    virtual Command *clone() override;
};


#endif //POSD_HW1_LOADCOMMAND_H
