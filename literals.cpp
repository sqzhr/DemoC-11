#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

//Литералы для численных типов
unsigned long long operator "" _min(unsigned long long minutes)
{
    return minutes * 60;
}

//Литералы для строковых типоv
std::string operator "" s(const char* str, size_t size)
{
    return std::string(str, size);
}

//сырые литералы
unsigned long long operator "" _b(const char* str)
{
    unsigned long long result = 0;
    size_t size = strlen(str);

    for (size_t i = 0; i < size; ++i)
    {
        //assert(str[i] == '1' || str[i] == '0');
        result |= (str[i] - '0') << (size - i - 1);
    }

    return result;
}

int main()
{
    std::cout << 5_min << std::endl; //300
    std::cout << "some string"s.length() << std::endl;
    std::cout << 101100_b << std::endl; // выведет 44

    _getch();
    return 0;
}

