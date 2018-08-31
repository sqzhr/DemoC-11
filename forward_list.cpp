#include <iostream>
#include <forward_list>
/*
–еализован в виде однонаправленного списка и не имеет никаких накладных расходов
по сравнению с аналогичной реализацией в C. ¬ отличие от std::list,
этот тип контейнера не поддерживает двунаправленную итерацию.
*/
int main ()
{
  std::forward_list<int> mylist = { 34, 77, 16, 2 };

  std::cout << "mylist contains:";
  for ( auto it = mylist.begin(); it != mylist.end(); ++it )
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}