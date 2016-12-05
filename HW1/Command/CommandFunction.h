//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_COMMANDFUNCTION_H
#define POSD_HW1_COMMANDFUNCTION_H


#include <string>
#include <vector>

class CommandFunction {
public:
    static unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch);
    static void printVector(const std::vector<std::string> &vector);
    static bool startWith(std::string origin, std::string key);
    static void getShapeArgumentFromString(std::vector<double>* argumentVector, std::string string);
    static void getComboArgumentFromString(std::vector<std::string>* argumentVector, std::string string);
};


#endif //POSD_HW1_COMMANDFUNCTION_H
