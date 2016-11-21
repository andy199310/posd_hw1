//
// Created by Green on 2016/11/21.
//

#include "MyDocument.h"
#include <sstream>
#include <streambuf>

void MyDocument::openFile(const std::string name) {
    file.open(name, std::fstream::in);
}

bool MyDocument::canOpenDocument(const std::string name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

std::string MyDocument::readFile() {
    std::string string((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());
    return string;
}
