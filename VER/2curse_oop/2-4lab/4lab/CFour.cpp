#include "cfour.h"
#include <iostream>

CFour::CFour() : CThree(), additionalData(0) {
}

CFour::CFour(const char* str, const COne& cOneObj, const char* extra, int data)
    : CThree(str, cOneObj, extra), additionalData(data) {
}

CFour::CFour(const CFour& other)
    : CThree(other), additionalData(other.additionalData) {
}

CFour& CFour::operator=(const CFour& other) {
    if (this == &other) {
        return *this;
    }
    CThree::operator=(other);
    additionalData = other.additionalData;
    return *this;
}

CFour::~CFour() {
}

int CFour::getAdditionalData() const {
    return additionalData;
}

void CFour::setAdditionalData(int data) {
    additionalData = data;
}

void CFour::print() const {
    CThree::print();
    std::cout << "CFour::additionalData = " << additionalData << std::endl;
}
