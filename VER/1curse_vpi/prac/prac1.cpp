#include <iostream>
#include <string>
using namespace std; 
int main () { 
string str;
// Контролируемая операция — конструктор умолчания}
cout << "str-> " << str << endl; 
cout << "---------------------------------------" << endl; 
cout << "str.length() = " << str.length() << endl; // Вызов
// функции для вычисления длины строки
cout << "---------------------------------------" << endl; 
cout << "str.capacity() = " << str.capacity() << endl;
// Вызов функции для определения общего размера памяти, выделенной для 
// строки str
cout << "-----------------------------------------" << endl;
return 0;
}
