#include "polynom.h"
#include <iostream>

int main()
{
  Term a;
  Term c;
  std::cin >> c;
  std::cin >> a;
  std::cout << "\n a+c:" << a + c;
  //_________________________________
  Polynomial d(3, 2);
  Polynomial e(213, 34);
  Polynomial f;
  f += e + d;
  std::cout << '\n'
            << f;
  f *= e;
  std::cout << '\n'
            << f;
  std::cout << "\nenter polynom:";
  Polynomial r;
  std::cin >> r;
  std::cout << r;
}