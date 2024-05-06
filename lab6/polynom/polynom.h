  #define MAX_INPUT 50

  #define TERM_INPUT 64
  #define POLYNOM_INPUT 512

  #include <iostream>
  #include <stdlib.h>
  #include <ctype.h>
  #include <string.h>

  class Polynomial;

  class Term
  {
    friend Polynomial;
    int mult;
    int exp;
  public:
    Term(int mult = 0, int exp = 0);

    friend Term operator+(const Term &f, const Term &s);
    friend std::istream &operator>>(std::istream &in, Term &term);
    friend std::ostream &operator<<(std::ostream &out, const Term &term);
    friend Polynomial operator+(const Polynomial &first, const Polynomial &second);
    friend Polynomial operator*(const Polynomial &first, const Polynomial &second);
    friend std::ostream &operator<<(std::ostream &out, const Polynomial &pol);
    friend std::istream &operator>>(std::istream &in, Polynomial &pol);
  };

  class Polynomial
  {
    Term *poly;
    unsigned degree;
    bool order_ = 0; // 0- по убыванию, 1- по возрастанию
  public:
    Polynomial(int mult_ = 0, int exp_ = 0);

    friend Polynomial operator+(const Polynomial &first, const Polynomial &second);

    friend Polynomial operator*(const Polynomial &first, const Polynomial &second);

    Polynomial &operator+=(const Polynomial &pol);

    Polynomial &operator*=(const Polynomial &pol);

    Polynomial(const Polynomial &pol);

    Polynomial &operator=(const Polynomial &pol);

    friend std::ostream &operator<<(std::ostream &out, const Polynomial &pol);

    friend std::istream &operator>>(std::istream &in, Polynomial &pol);
  };