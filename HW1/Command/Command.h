//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_COMMAND_H
#define POSD_HW1_COMMAND_H

#include <string>

class Command{
public:
    virtual void execute(std::string command) = 0;
};

#endif //POSD_HW1_COMMAND_H
