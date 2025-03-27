#ifndef CTHREE_H
#define CTHREE_H

#include "ctwo.h"

class CThree : public CTwo {
private:
    char* extraField;

public:
    // Конструктор по умолчанию
    CThree();

    // Конструктор с параметрами 
    CThree(const char* str, const COne& cOneObj, const char* extra);

    // Конструктор копирования
    CThree(const CThree& other);

    // Оператор присваивания
    CThree& operator=(const CThree& other);

    // Виртуальный деструктор
    virtual ~CThree();

    // Методы доступа к новому полю
    const char* getExtraField() const;
    void setExtraField(const char* extra);

    // Переопределяем виртуальный метод print()
    virtual void print() const override;
};

#endif // CTHREE_H
