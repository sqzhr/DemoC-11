template<class ... Types> void f(Types ... args) {}

int main() {  
  f();       // OK: args contains no arguments
  f(1);      // OK: args contains one argument: int
  f(2, 1.0); // OK: args contains two arguments: int and double
}