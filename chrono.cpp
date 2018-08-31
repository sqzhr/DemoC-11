#include <chrono>
#include <iostream>
#include <ratio>
using namespace std;

void foo()
{
}

int main() {
    //ratio шаблонный класс, реализующий compile-time обыкновенную дробь (m/n)
    using Mm = std::ratio<1>; //знаменатель
    using Inches = std::ratio<254, 10>;
    using Metre = std::ratio<1000, 1>;

    //duration
    typedef std::chrono::duration<int, std::ratio<1, 100000000>> shakes;
    typedef std::chrono::duration<int, std::centi> jiffies;
    typedef std::chrono::duration<float, std::ratio<12096,10000>> microfortnights;
    typedef std::chrono::duration<float, std::ratio<3155,1000>> nanocenturies;

    std::chrono::seconds sec(1);

    std::cout << "1 second is:\n";

    std::cout << std::chrono::duration_cast<shakes>(sec).count()
              << " shakes\n";
    std::cout << std::chrono::duration_cast<jiffies>(sec).count()
              << " jiffies\n";
    std::cout << std::chrono::duration_cast<microfortnights>(sec).count()
              << " microfortnights\n";
    std::cout << std::chrono::duration_cast<nanocenturies>(sec).count()
              << " nanocenturies\n";

    //time_point
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    //или
    std::chrono::steady_clock::time_point start1 = std::chrono::steady_clock::now();
    //или
    auto start2 = std::chrono::steady_clock::now();

   foo();
   if (std::chrono::steady_clock::now() < start + 1s)
       std::cout << "Less than a second!\n";

   //time since epoch
   auto now = std::chrono::system_clock::now();
   std::chrono::system_clock::duration tse = now.time_since_epoch();

   //convert to number
   auto now1 = std::chrono::system_clock::now();
   time_t now_t = std::chrono::system_clock::to_time_t(now);
   auto now2 = std::chrono::system_clock::from_time_t(now_t);

   return 0;
}