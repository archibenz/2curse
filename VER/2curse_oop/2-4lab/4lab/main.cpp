#include <iostream>
#include "cone.h"
#include "ctwo.h"
#include "cthree.h"
#include "cfour.h"

// Глобальная функция для демонстрации полиморфизма
void printAll(CTwo* arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i]->print();
        std::cout << "----------------------" << std::endl;
    }
}

int main() {
    std::cout << "===== Лаб. работа №2 (Композиция) =====\n";
    {
        // COne
        COne oneDefault;
        COne oneParam(3.14f, "Hello, COne!");
        COne oneCopy(oneParam);
        oneDefault = oneParam;

        oneDefault.print();
        oneParam.print();
        oneCopy.print();

        // CTwo
        CTwo twoDefault;
        CTwo twoParam("String for CTwo", oneParam);
        CTwo twoCopy(twoParam);
        twoDefault = twoParam;

        twoDefault.print();
        twoParam.print();
        twoCopy.print();
    }

    std::cout << "\n===== Лаб. работа №3 (Наследование) =====\n";
    {
        // CThree
        COne oneForThree(2.71f, "String in COne");
        CThree threeDefault;
        CThree threeParam("BaseString", oneForThree, "ExtraFieldData");
        CThree threeCopy(threeParam);
        threeDefault = threeParam;

        threeDefault.print();
        threeParam.print();
        threeCopy.print();
    }

    std::cout << "\n===== Лаб. работа №4 (Виртуальные функции) =====\n";
    {
        // CFour
        COne oneForFour(1.23f, "COne in CFour");
        CFour fourDefault;
        CFour fourParam("Base in CFour", oneForFour, "Extra in CFour", 42);
        CFour fourCopy(fourParam);
        fourDefault = fourParam;

        fourDefault.print();
        fourParam.print();
        fourCopy.print();
    }

    std::cout << "\n===== Демонстрация полиморфизма =====\n";
    {
        CTwo* arr[3];
        arr[0] = new CTwo("CTwo example", COne(0.0f, "from arr[0]"));
        arr[1] = new CThree("CThree example", COne(100.0f, "from arr[1]"), "Extra example");
        arr[2] = new CFour("CFour example", COne(999.9f, "from arr[2]"), "Extra for four", 777);

        printAll(arr, 3);

        for (int i = 0; i < 3; i++) {
            delete arr[i];
        }
    }

    return 0;
}
