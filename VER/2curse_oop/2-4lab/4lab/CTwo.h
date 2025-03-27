#ifndef CTWO_H
#define CTWO_H

#include "cone.h"

class CTwo {
protected:
    char* s;   // динамическая C-строка
    COne obj;  // вложенный объект класса COne

public:
    // Конструктор по умолчанию
    CTwo();

    // Конструктор с параметрами
    CTwo(const char* str, const COne& cOneObj);

    // Конструктор копирования
    CTwo(const CTwo& other);

    // Виртуальный деструктор
    virtual ~CTwo();

    // Оператор присваивания
    CTwo& operator=(const CTwo& other);

    // Методы доступа
    const char* getS() const;
    void setS(const char* str);

    COne getObj() const;
    void setObj(const COne& cOneObj);

    // Виртуальный метод print() для полиморфизма
    virtual void print() const;
};

#endif // CTWO_H
