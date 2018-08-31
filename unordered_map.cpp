#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

struct S
{
    int i;
    std::string s;
};

int main()
{
    std::unordered_map<std::string, S> m;
    
    m.emplace(std::make_pair<std::string, S>("one", {1, "cat"}));
    m.emplace(std::make_pair<std::string, S>("two", {2, "dogs"}));
    m.emplace(std::make_pair<std::string, S>("three", {3, "cows"}));
    
    for (auto& p : m) {
        std::cout << p.first << " (" << p.second.i << ") " << p.second.s<< std::endl;
    }
}
