#include <iostream>
using namespace std;

constexpr int sum (int a, int b)
{
    return a + b;
}

void func()
{
    constexpr int c = sum (5, 12); // значение переменной будет посчитано на этапе компиляции
}

int sum2 (int a, int b)
{
    return a + b;
}

constexpr int new_sum (int a, int b)
{
    return a + b;
}

void func2()
{
    constexpr int a1 = new_sum (5, 12); // ОК: constexpr-переменная
//  constexpr int a2 = sum (5, 12); // ошибка: функция sum не является constexp-выражением
    int a3 = new_sum (5, 12); // ОК: функция будет вызвана на этапе компиляции
    int a4 = sum2 (5, 12); // ОК
}
 
int main() {
    func();
    func2();
    return 0;
}