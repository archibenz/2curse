#ifndef CFOUR_H
#define CFOUR_H

#include "cthree.h"

class CFour : public CThree {
private:
    int additionalData;

public:
    // Конструктор по умолчанию
    CFour();

    // Конструктор с параметрами
    CFour(const char* str, const COne& cOneObj, const char* extra, int data);

    // Конструктор копирования
    CFour(const CFour& other);

    // Оператор присваивания
    CFour& operator=(const CFour& other);

    // Виртуальный деструктор
    virtual ~CFour();

    // Методы доступа к новому полю
    int getAdditionalData() const;
    void setAdditionalData(int data);

    // Переопределяем виртуальный метод print()
    virtual void print() const override;
};

#endif // CFOUR_H
