#include <atomic>

//std::atomic is specialized for all integral types to provide member 
//functions specific to integral (like operators ++, --, fetch_add, fetch_sub, ...).

struct AtomicCounter {
    std::atomic<int> value;

    void increment(){
        ++value;
    }

    void decrement(){
        --value;
    }

    int get(){
        return value.load();
    }
};

int main()
{
}