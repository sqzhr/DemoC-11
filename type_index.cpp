#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>

/*
Класс type_index - это класс-оболочка для объекта типа std::type_info, 
которая позволяет использовать объекты этого класса в качестве индекса 
в ассоциативных и в неупорядоченных контейнерах. Отношения с объектом type_info
осуществляется с помощью указателя
*/
 
struct A {
    virtual ~A() {}
};
 
struct B : A {};
struct C : A {};
 
int main()
{
    std::unordered_map<std::type_index, std::string> type_names;
 
    type_names[std::type_index(typeid(int))] = "int";
    type_names[std::type_index(typeid(double))] = "double";
    type_names[std::type_index(typeid(A))] = "A";
    type_names[std::type_index(typeid(B))] = "B";
    type_names[std::type_index(typeid(C))] = "C";
 
    int i;
    double d;
    A a;
 
    // храним указатель на тип A
    std::unique_ptr<A> b(new B);
    std::unique_ptr<A> c(new C);
 
    std::cout << "i является " << type_names[std::type_index(typeid(i))] << '\n';
    std::cout << "d является " << type_names[std::type_index(typeid(d))] << '\n';
    std::cout << "a является " << type_names[std::type_index(typeid(a))] << '\n';
    std::cout << "b является " << type_names[std::type_index(typeid(*b))] << '\n';
    std::cout << "c является " << type_names[std::type_index(typeid(*c))] << '\n';
}