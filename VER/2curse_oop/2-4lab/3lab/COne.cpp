#include "COne.h"

COne::COne(float f, const char* ps) : f(f) {
    this->ps = new char[strlen(ps) + 1];
    strcpy(this->ps, ps);
}

COne::COne(const COne& other) : f(other.f) {
    ps = new char[strlen(other.ps) + 1];
    strcpy(ps, other.ps);
}

COne& COne::operator=(const COne& other) {
    if (this != &other) {
        delete[] ps;
        f = other.f;
        ps = new char[strlen(other.ps) + 1];
        strcpy(ps, other.ps);
    }
    return *this;
}

COne::~COne() {
    delete[] ps;
}

void COne::print() const {
    std::cout << "COne(f: " << f << ", ps: " << ps << ")";
}
