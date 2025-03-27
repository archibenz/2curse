#ifndef CONE_H
#define CONE_H

#include <iostream>
#include <cstring>

class COne {
private:
    float f;
    char* ps;

public:
    COne(float f = 0.0, const char* ps = "");
    COne(const COne& other);
    COne& operator=(const COne& other);
    ~COne();

    void print() const;
};

#endif // CONE_H
