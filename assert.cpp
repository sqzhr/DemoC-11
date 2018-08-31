#include <iostream>
#include <array>
#include <cassert> // для assert()
 
int getArrayValue(const std::array<int, 10> &array, int index)
{
    // предполагается, что значение index-а находится между 0 и 8
    assert(index >= 0 && index <= 8);

    return array[index];
}

static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) == 4, "int must be 4 bytes");
 
int main()
{
    return 0;
}