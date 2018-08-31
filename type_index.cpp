#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>

/*
����� type_index - ��� �����-�������� ��� ������� ���� std::type_info, 
������� ��������� ������������ ������� ����� ������ � �������� ������� 
� ������������� � � ��������������� �����������. ��������� � �������� type_info
�������������� � ������� ���������
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
 
    // ������ ��������� �� ��� A
    std::unique_ptr<A> b(new B);
    std::unique_ptr<A> c(new C);
 
    std::cout << "i �������� " << type_names[std::type_index(typeid(i))] << '\n';
    std::cout << "d �������� " << type_names[std::type_index(typeid(d))] << '\n';
    std::cout << "a �������� " << type_names[std::type_index(typeid(a))] << '\n';
    std::cout << "b �������� " << type_names[std::type_index(typeid(*b))] << '\n';
    std::cout << "c �������� " << type_names[std::type_index(typeid(*c))] << '\n';
}