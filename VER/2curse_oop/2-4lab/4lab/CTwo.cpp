#include "ctwo.h"
#include <cstring>
#include <iostream>

CTwo::CTwo() : s(nullptr), obj() {
    s = new char[1];
    s[0] = '\0';
}

CTwo::CTwo(const char* str, const COne& cOneObj) : s(nullptr), obj(cOneObj) {
    if (str) {
        s = new char[strlen(str) + 1];
        strcpy(s, str);
    } else {
        s = new char[1];
        s[0] = '\0';
    }
}

CTwo::CTwo(const CTwo& other) : s(nullptr), obj(other.obj) {
    if (other.s) {
        s = new char[strlen(other.s) + 1];
        strcpy(s, other.s);
    } else {
        s = new char[1];
        s[0] = '\0';
    }
}

CTwo::~CTwo() {
    delete[] s;
}

CTwo& CTwo::operator=(const CTwo& other) {
    if (this == &other) {
        return *this;
    }
    obj = other.obj;
    delete[] s;
    if (other.s) {
        s = new char[strlen(other.s) + 1];
        strcpy(s, other.s);
    } else {
        s = new char[1];
        s[0] = '\0';
    }
    return *this;
}

const char* CTwo::getS() const {
    return s;
}

void CTwo::setS(const char* str) {
    delete[] s;
    if (str) {
        s = new char[strlen(str) + 1];
        strcpy(s, str);
    } else {
        s = new char[1];
        s[0] = '\0';
    }
}

COne CTwo::getObj() const {
    return obj;
}

void CTwo::setObj(const COne& cOneObj) {
    obj = cOneObj;
}

void CTwo::print() const {
    std::cout << "CTwo::s = " << s << std::endl;
    obj.print();
}
