#include <iostream>

#include "../cppunitlite/TestHarness.h"

#include "unitTest/utMain.h"

int main(){
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}
