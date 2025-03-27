#include "COne.h"
#include "CTwo.h"
#include "CThree.h"

int main() {
    std::cout << "=== Testing Lab 3 ===" << std::endl;

    COne c1(3.14, "Hello");
    CThree c3("World", c1, "NewFeature");

    c3.print();

    return 0;
}
