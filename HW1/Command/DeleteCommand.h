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
    std::map<std::string, Media*> _mediaMap;
    Media* _deleteTarget;
    std::vector<std::string> _parentVector;
public:
    DeleteCommand(Application *application);

public:
    virtual void execute(std::string command) override;

    virtual bool checkValid(std::string command) override;

    virtual bool needUndo() override;

    virtual void undo() override;

    virtual void redo() override;

    virtual Command *clone() override;
};


#endif //POSD_HW1_DELETECOMMAND_H
