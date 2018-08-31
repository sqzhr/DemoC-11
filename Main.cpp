#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <memory>
#include <math.h>
#include <algorithm>
#include <time.h>
#include "Carry.h"

double sum(std::initializer_list<double>);
double average(const std::initializer_list<double>&);

//using =
template <typename T>
using arr12 = std::array<T, 12>;
//arr12<double> a;

//decltype
template<class T1, class T2>
void ft(T1 x, T2 y)
{
    decltype (x + y) = x + y;
}

template<class T1, class T2>
auto gt(T1 x, T2 y) -> decltype(x + y)
{
    return x + y;
}

//noexept
void f875(short, short) noexcept;

//enums
//do not support implicit convertion to integer type
enum Old1 {yes, no, maybe};
enum class New1{never, simetimes, often, always};
enum struct New2 { never, lever, sever };

using namespace std;

//smart pointers
unique_ptr<string> demo(const char*);

//Обобщённые константные выражения
constexpr int GiveFive() {return 5;}
int some_value[GiveFive() + 7];

constexpr double accelerationOfGravity = 9.8;
constexpr double moonGravity = accelerationOfGravity / 6;




int main()
{
    //std::initializer_list

    //from larger to smaller type cast
//    char c1 = 1.57e27; //behaviour is undefined
    //char c2 { 1.57e27 }; //compile-time error
    //vector<int> values{ 10, 8, 5.5 }; //compile-time error
    char c3 { 66 }; //allowed as the value is in the right range
    double c4 { 66 }; //from smaller to bigger type cast is allowed 

    initializer_list<double> d1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << "SUM: " << sum(d1) << endl;
    cout << "AVE: " << average(d1) << endl;

    //decltype 
    //creates a variable of type that is already specified by the expression
    double x; 
    int n;
    decltype (x*n) q; //double
    decltype (&x) pd; //double*

    //using =
    typedef const char* pc1;
    using pc2 = const char*; //just different forms recording

    //nullptr
    //pointer type that could not be converted to int, except one case
    (0 == nullptr) ? cout << "yes"<<endl : cout << "no"<<endl;

    //smart pointers
    string vc("AAAAA");
    //shared_ptr<string> pvc(&vc); //NOPE!!! 

    auto_ptr<string> p1(new string("auto"));
    auto_ptr<string> p2;
    p2 = p1; //carry

    unique_ptr<string> p3(new string("auto"));
    unique_ptr<string> p4;
    //p4 = p3; NOPE! 

    unique_ptr<string> ps1, ps2;
    ps1 = demo("Uniqely special");
    ps2 = move(ps1);
    ps1 = demo("and more");
    cout << *ps2 <<" "<< *ps1 << endl;

    //enums
    int f = int(New1::simetimes); 
    cout << "f = " << f << endl;

    //new for record
    double prices[5] = { 4.99, 10.99, 6.87, 7.99, 8.49 };
    for (auto x : prices)
        cout << x << endl;
    //if we want to change elements
    vector<int> vi(6);
    for (auto &x : vi)
        x = rand();
    for (auto x : vi)
        cout << x << endl;

    //rvalue
    int && r1 = 13;
    int && r2 = sqrt(2.0);

    //carry
    Carry one(10, 'x');
    Carry two = one;
    Carry three(20, 'o');
    Carry four(one + three);
    cout << "object one: " << endl;
    one.ShowData();
    cout << "object two: " << endl;
    two.ShowData();
    cout << "object three: " << endl;
    three.ShowData();
    cout << "object four: " << endl;
    four.ShowData();

    //lambda
    vector<int> numbers(39);
    srand(time(0));
    generate(numbers.begin(), numbers.end(), rand);
    int count1 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
    int count2 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });

    auto mod3 = [](int x) {return x % 3 == 0; };

    int count13 = 0;
    for_each(numbers.begin(), numbers.end(),
        [&count13](int x) {count13 += x % 13 == 0; });

    _getch();
    return 0;
}


//an object can be passed by const reference or by value as in following two examples
double sum(std::initializer_list<double> il)
{
    double tot = 0;
    for (auto p = il.begin(); p != il.end(); p++)
        tot += *p;
    return tot;
}

double average(const initializer_list<double> & ril)
{
    double tot = 0;
    int n = ril.size();
    double ave = 0.0;
    if (n > 0)
    {
        for (auto p = ril.begin(); p != ril.end(); p++)
            tot += *p;
        ave = tot / n;
    }
    return ave;
}

//smart pointer
unique_ptr<string> demo(const char* s)
{
    unique_ptr<string> temp(new string(s));
    return temp;
}

