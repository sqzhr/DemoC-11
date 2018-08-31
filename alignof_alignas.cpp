#include <iostream>
 
struct Foo {
    int   i;
    float f;
    char  c;
};
 
struct Empty {};
 
struct alignas(64) Empty64 {};

int main()
{
    std::cout << "Alignment of"  "\n"
        "- char             : " << alignof(char)    << "\n"
        "- pointer          : " << alignof(int*)    << "\n"
        "- class Foo        : " << alignof(Foo)     << "\n"
        "- empty class      : " << alignof(Empty)   << "\n"
        "- alignas(64) Empty: " << alignof(Empty64) << "\n";
    
    //Выравнивание - это ограничение, на котором память может хранить значение первого байта. 
    //Выравнивание 16 означает, что адреса памяти, кратные 16, 
    //являются единственными действительными адресами.
    alignas(16) int a[4];
    alignas(1024) int b[4];
    printf("%p\n", a);
    printf("%p", b);
}