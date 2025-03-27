#include "CThree.h"
#include <iostream>

CThree::CThree(const std::string& s, const COne& obj, const std::string& extra_field)
    : CTwo(s, obj), extra_field(extra_field) {}

void CThree::print() const {
    CTwo::print();
    std::cout << "CThree(extra_field: " << extra_field << ")" << std::endl;
}
