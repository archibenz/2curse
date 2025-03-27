#include <iostream>
#include <string>
using namespace std;

int main() {
    string s("ad");
    size_t cap_old = s.capacity();
    size_t cap_cur = s.capacity();
    int max_iterations = 30; // Максимальное количество итераций

    for (int i = 0; i < max_iterations; ++i) {
        cap_old = s.capacity();
        s.push_back('a'); // Увеличиваем длину строки на 2
        cap_cur = s.capacity();
        cout << "При длине строки " << s.size() << " ёмкость увеличилась до " << cap_cur << std::endl;
    }
    return 0;
}