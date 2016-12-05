//
// Created by Green on 2016/12/5.
//

#include <iostream>
#include "ShowCommand.h"

ShowCommand::ShowCommand(Application *application):_application(application) {

}

void ShowCommand::execute(std::string command) {
    std::vector<std::string> mediaNameVector = _application->getMediaNameVector();
    for(unsigned int i=0; i<mediaNameVector.size(); i++){
        _application->writeOutput(mediaNameVector.at(i));
    }
}
