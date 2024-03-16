#include <iostream>

#include "myvector.h"

class MySet : public MyVector {
private:
  int q_find(const char *el);
 public:
  MySet(char *el = NULL) : MyVector(el){};
  bool operator==(MySet &s);
  MySet &operator+=(MySet &s);
  MySet &operator-=(MySet &s);
  MySet &operator*=(MySet &s);
  void add_element(const char *el);
  void delete_element(char *el);
  bool is_element(char *el);
  friend std::ostream &operator<<(std::ostream &out, MySet &s);
  friend MySet operator+(MySet &s1, MySet &s2);
  friend MySet operator-(MySet &s1, MySet &s2);
  friend MySet operator*(MySet &s1, MySet &s2);
};
