#include <iostream>
#include <string>
using std :: cout;
using std :: cin;
using std :: endl;
using std :: string;
int main()
{
string str1("1234");
string str2("5678");
str2 += str1; // Конролируемая операция перегруженный составной
// оператор присваивания: +=
// Альтернативное решение: str2.append(str1);
cout << "str2-> " << str2 << endl;
cout << "-----------------------------------------" << endl;
cout << "str2.length() = " << str2.length() << endl;
cout << "-----------------------------------------" << endl;
cout << "str2.capacity() = " << str2.capacity() << endl;
cout << "-----------------------------------------" << endl;
return 0;
}
