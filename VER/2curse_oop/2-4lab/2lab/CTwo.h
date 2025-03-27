#ifndef CTWO_H
#define CTWO_H

#include <string>
#include "COne.h"

class CTwo {
private:
    std::string s;
    COne obj;

public:
    CTwo(const std::string& s = "", const COne& obj = COne());
    void print() const;
};

#endif // CTWO_H
