#include <thread>
#include <iostream>
#include <system_error>
 /*
 std::system_error is the type of the exception thrown by various library functions 
 typically the functions that interface with the OS facilities
 */
int main()
{
    try {
        std::thread().detach(); // attempt to detach a non-thread
    } catch(const std::system_error& e) {
        std::cout << "Caught system_error with code " << e.code() 
                  << " meaning " << e.what() << '\n';
    }
}