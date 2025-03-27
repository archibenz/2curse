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

    virtual void print() const; // Добавлено virtual для поддержки полиморфизма

    virtual ~CTwo() = default; // Виртуальный деструктор для корректного наследования
};

#endif // CTWO_H
