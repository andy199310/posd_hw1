//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_DEFCOMMAND_H
#define POSD_HW1_DEFCOMMAND_H

#include "../Application.h"
#include "Command.h"

class DefCommand : public Command{
private:
    Application *_application;
public:
    DefCommand(Application *application);

public:
    virtual void execute(std::string command) override;

    virtual bool checkValid(std::string command) override;
};


#endif //POSD_HW1_DEFCOMMAND_H
