#include "../cppunitlite/TestHarness.h"
#include "unitTest/utMain.h"
#include "Shell.h"

#define OPEN_SHELL 0

int main(){
    TestResult tr;
    TestRegistry::runAllTests(tr);

    if(OPEN_SHELL){
        Application application;
        Shell shell(&application);
        shell.start();
    }

    return 0;
}
