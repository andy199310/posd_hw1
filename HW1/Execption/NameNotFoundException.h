//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_NAMENOTFOUNDEXECPTION_H
#define POSD_HW1_NAMENOTFOUNDEXECPTION_H


#include <string>

class NameNotFoundException {
private:
    std::string _expectedName;
public:
    NameNotFoundException(std::string expectedName);
};


#endif //POSD_HW1_NAMENOTFOUNDEXECPTION_H
