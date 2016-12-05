//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_SAVECOMMAND_H
#define POSD_HW1_SAVECOMMAND_H


#include "../Shell.h"
#include "Command.h"

class SaveCommand : public Command{
private:
    Shell *_shell;
public:
    virtual void execute(std::string command) override;

    virtual bool checkValid(std::string command) override;

public:
    SaveCommand(Shell *shell);
};


#endif //POSD_HW1_SAVECOMMAND_H
