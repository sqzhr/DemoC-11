#include <iostream>

using namespace std;

int main() {
  // represents the string: hello
  //goodbye
  const wchar_t* newline = LR"(hello
  goodbye)";

  wcout << newline << endl;

  const char* good_parens = R"xyz()")xyz";
  wcout<<good_parens<<endl;

  // represents the string: An unescaped \ character
const char* raw_narrow = R"(An unescaped \ character)";

// represents the string: An unescaped " character
const wchar_t* raw_wide = LR"(An unescaped " character)";

wcout<<raw_narrow<<endl;
wcout<<raw_wide<<endl;
}