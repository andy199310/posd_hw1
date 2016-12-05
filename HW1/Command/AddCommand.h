//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_ADDCOMMAND_H
#define POSD_HW1_ADDCOMMAND_H

#include "../Application.h"
#include "Command.h"

class AddCommand : public Command{
private:
    Application *_application;
public:
    AddCommand(Application *application);

public:
    virtual void execute(std::string command) override;
};


#endif //POSD_HW1_ADDCOMMAND_H
