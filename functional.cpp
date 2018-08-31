#include <iostream>
#include <functional>

struct A {
    A(int num) : num_(num){}
    void printNumberLetter(char c) const {std::cout << "Number: " << num_  << " Letter: " << c << std::endl;}
    int num_;
};

void printLetter(char c)
{
    std::cout << c << std::endl;
}

struct B {
    void operator() () {std::cout << "B()" << std::endl;}
};

int main()
{
    // Содержит функцию.
    std::function<void(char)> f_print_Letter = printLetter;
    f_print_Letter('Q');

    // Содержит лямбда-выражение.
    std::function<void()> f_print_Hello = [] () {std::cout << "Hello world!" << std::endl;};
    f_print_Hello();

    // Содержит связыватель.
    std::function<void()> f_print_Z = std::bind(printLetter, 'Z');
    f_print_Z();

    // Содержит вызов метода класса.
    std::function<void(const A&, char)> f_printA = &A::printNumberLetter;
    A a(10);
    f_printA(a, 'A');

    // Содержит функциональный объект.
    B b;
    std::function<void()> f_B = b;
    f_B();
}