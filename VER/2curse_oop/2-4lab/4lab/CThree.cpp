#include "cthree.h"
#include <cstring>
#include <iostream>

CThree::CThree() : CTwo(), extraField(nullptr) {
    extraField = new char[1];
    extraField[0] = '\0';
}

CThree::CThree(const char* str, const COne& cOneObj, const char* extra)
    : CTwo(str, cOneObj), extraField(nullptr) {
    if (extra) {
        extraField = new char[strlen(extra) + 1];
        strcpy(extraField, extra);
    } else {
        extraField = new char[1];
        extraField[0] = '\0';
    }
}

CThree::CThree(const CThree& other)
    : CTwo(other), extraField(nullptr) {
    if (other.extraField) {
        extraField = new char[strlen(other.extraField) + 1];
        strcpy(extraField, other.extraField);
    } else {
        extraField = new char[1];
        extraField[0] = '\0';
    }
}

CThree& CThree::operator=(const CThree& other) {
    if (this == &other) {
        return *this;
    }
    CTwo::operator=(other);
    delete[] extraField;
    if (other.extraField) {
        extraField = new char[strlen(other.extraField) + 1];
        strcpy(extraField, other.extraField);
    } else {
        extraField = new char[1];
        extraField[0] = '\0';
    }
    return *this;
}

CThree::~CThree() {
    delete[] extraField;
}

const char* CThree::getExtraField() const {
    return extraField;
}

void CThree::setExtraField(const char* extra) {
    delete[] extraField;
    if (extra) {
        extraField = new char[strlen(extra) + 1];
        strcpy(extraField, extra);
    } else {
        extraField = new char[1];
        extraField[0] = '\0';
    }
}

void CThree::print() const {
    CTwo::print();
    std::cout << "CThree::extraField = " << extraField << std::endl;
}
