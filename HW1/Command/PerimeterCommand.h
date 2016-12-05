//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_PERIMETERCOMMAND_H
#define POSD_HW1_PERIMETERCOMMAND_H

#include "../Application.h"
#include "Command.h"

class PerimeterCommand : public Command{
private:
    Application *_application;
public:
    PerimeterCommand(Application *application);

public:
    virtual void execute(std::string command) override;
};


#endif //POSD_HW1_PERIMETERCOMMAND_H