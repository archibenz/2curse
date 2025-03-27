#include "cone.h"
#include <cstring>   // для strlen, strcpy
#include <iostream>  // для std::cout

COne::COne() : f(0.0f) {
    ps = new char[1];
    ps[0] = '\0';
}

COne::COne(float value, const char* str) : f(value) {
    if (str) {
        ps = new char[strlen(str) + 1];
        strcpy(ps, str);
    } else {
        ps = new char[1];
        ps[0] = '\0';
    }
}

COne::COne(const COne& other) : f(other.f) {
    ps = new char[strlen(other.ps) + 1];
    strcpy(ps, other.ps);
}

COne& COne::operator=(const COne& other) {
    if (this == &other) {
        return *this; // защита от самоприсваивания
    }
    f = other.f;
    delete[] ps;
    ps = new char[strlen(other.ps) + 1];
    strcpy(ps, other.ps);
    return *this;
}

COne::~COne() {
    delete[] ps;
}

float COne::getF() const {
    return f;
}

void COne::setF(float value) {
    f = value;
}

const char* COne::getPs() const {
    return ps;
}

void COne::setPs(const char* str) {
    delete[] ps;
    if (str) {
        ps = new char[strlen(str) + 1];
        strcpy(ps, str);
    } else {
        ps = new char[1];
        ps[0] = '\0';
    }
}

void COne::print() const {
    std::cout << "COne::f = " << f
              << ", ps = " << ps << std::endl;
}
