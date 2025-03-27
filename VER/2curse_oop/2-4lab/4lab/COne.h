#ifndef CONE_H
#define CONE_H

class COne {
private:
    float f;      // число с плавающей точкой
    char* ps;     // указатель на C-строку

public:
    // Конструктор по умолчанию
    COne();

    // Конструктор с параметрами
    COne(float value, const char* str);

    // Конструктор копирования
    COne(const COne& other);

    // Оператор присваивания
    COne& operator=(const COne& other);

    // Деструктор
    ~COne();

    // Методы доступа (геттеры и сеттеры)
    float getF() const;
    void setF(float value);

    const char* getPs() const;
    void setPs(const char* str);

    // Метод print()
    void print() const;
};

#endif // CONE_H
