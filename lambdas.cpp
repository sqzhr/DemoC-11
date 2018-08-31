#include <functional
#include <iostream>

int main()
{

    using namespace std;  

    // Assign the lambda expression that adds two numbers to an auto variable.
    auto f1 = [](int x, int y) { return x + y; };

    cout << f1(2, 3) << endl;

    // Assign the same lambda expression to a function object.
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };

    cout << f2(3, 4) << endl;
    //& captures by reference
    //= captures by value
    int x = 1;
    auto valueLambda = [=]() { cout << x << endl; };
    auto refLambda = [&]() { cout << x << endl; };
    x = 13;
    valueLambda();
    refLambda();
    
    //this pointer is always captured by value. 
    //[this]() { ++this->a; }
    //this is captured by value, but this is a pointer, so a is referenced through this.
    //auto copy = this->a;
    //[copy]() mutable { ++copy; }

}