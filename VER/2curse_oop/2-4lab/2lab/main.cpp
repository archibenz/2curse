#include "COne.h"
#include "CTwo.h"

int main() {
    std::cout << "=== Testing Lab 2 ===" << std::endl;

    COne c1(3.14, "Hello");
    CTwo c2("World", c1);

    c2.print();

    return 0;
}
