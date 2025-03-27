#ifndef CTHREE_H
#define CTHREE_H

#include "CTwo.h"
#include <string>

class CThree : public CTwo {
private:
    std::string extra_field;

public:
    CThree(const std::string& s = "", const COne& obj = COne(), const std::string& extra_field = "ExtraField");

    void print() const override; // Теперь корректно работает с виртуальной функцией
};

#endif // CTHREE_H
