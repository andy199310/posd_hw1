//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_DELETECOMMAND_H
#define POSD_HW1_DELETECOMMAND_H

#include "../Application.h"
#include "Command.h"

class DeleteCommand : public Command{
private:
    Application *_application;
public:
    DeleteCommand(Application *application);

public:
    virtual void execute(std::string command) override;

    virtual bool checkValid(std::string command) override;
};


#endif //POSD_HW1_DELETECOMMAND_H
