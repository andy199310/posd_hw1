//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_AREACOMMAND_H
#define POSD_HW1_AREACOMMAND_H


#include "../Application.h"
#include "Command.h"

class AreaCommand : public Command{
private:
    Application *_application;
public:
    AreaCommand(Application *application);

public:
    virtual void execute(std::string command) override;

    virtual bool checkValid(std::string command) override;
};


#endif //POSD_HW1_AREACOMMAND_H
