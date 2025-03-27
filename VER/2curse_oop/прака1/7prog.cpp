#include <iostream>
#include <string>

int main() {
    std::string s;
    size_t cap_old = s.capacity();
    size_t cap_cur = s.capacity();
    int count = 0;

    for (int i = 0; i < 1000; ++i) {
        cap_old = s.capacity();
        s.push_back('a');  // Добавляем один символ в конец строки
        cap_cur = s.capacity();
        if (cap_old != cap_cur) {
            ++count;  // Увеличиваем счетчик, если емкость изменилась
        }
    }

    std::cout << "Количество расширений строки: " << count << std::endl;
    return 0;
}