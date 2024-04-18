#include "polynom.h"
#include <iostream>

int main(){
  Term a(34,2);
  Term b(243,21);
  Term c(12,2);
  std::cin>>c;
  std::cin>>a;
 //std::cout<<"a+b:"<<a+b;
  std::cout<<"\n a+c:"<<a;
  //_________________________________
  Polynomial d(3,2);
  Polynomial e(213,34);
  Polynomial f = d+e+ Polynomial(23,4);
  std::cout<<'\n'<< f;

}