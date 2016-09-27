#include <iostream>

#include "..\cppunitlite\TestHarness.h"

#include "utRectangle.h"
#include "utCircle.h"
#include "utTriangle.h"
#include "utshapeFunctoin.h"

int main(){
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}
