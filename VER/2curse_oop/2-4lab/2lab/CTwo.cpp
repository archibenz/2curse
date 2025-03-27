#include "CTwo.h"
#include <iostream>

CTwo::CTwo(const std::string& s, const COne& obj) : s(s), obj(obj) {}

void CTwo::print() const {
    std::cout << "CTwo(s: " << s << ", obj: ";
    obj.print();
    std::cout << ")" << std::endl;
}
