#define MAX_INPUT 50

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
  Term(int mult = 0, int exp = 0) : mult(mult), exp(exp) {}
  friend Term operator+(const Term &f, const Term &s)
  {
    if (f.exp == s.exp)
    {
      return Term(f.mult + s.mult, f.exp);
    }
    else
    {
      std::cerr << " can't slozhit' terms, first term returned ";
      return f;
    }
  }

  friend std::istream &operator>>(std::istream &in, Term &term)
  {
    char input[20];
    in >> input;

    char finalws[20];
    int finalIndex = 0;

    for (int i = 0; input[i] != '\0'; ++i)
    {
      if (input[i] != ' ')
      {
        finalws[finalIndex++] = input[i];
      }
    }
    finalws[finalIndex] = '\0';

    term.mult = 0;
    term.exp = 0;
    int len = strlen(finalws);
    int xIndex = -1;
    int stIndex = -1;

    for (int i = 0; i < len; ++i)
    {
      if (finalws[i] == 'x')
      {
        xIndex = i;
        break;
      }
    }

    if (xIndex != -1)
    {
      for (int i = xIndex + 1; i < len; ++i)
      {
        if (finalws[i] == '^')
        {
          stIndex = i;
          break;
        }
      }
    }

    if (xIndex == -1)
    {
      term.mult = atoi(finalws);
    }
    else if (xIndex == 0 || (xIndex == 1 && finalws[0] == '-'))
    {
      term.mult = (finalws[0] == '-') ? -1 : 1;
    }
    else
    {
      char coeffPart[20] = {0};
      strncpy(coeffPart, finalws, xIndex);
      term.mult = atoi(coeffPart);
    }

    if (xIndex != -1 && stIndex == -1)
    {
      term.exp = 1;
    }
    else if (stIndex != -1)
    {
      char expPart[20] = {0};
      strcpy(expPart, finalws + stIndex + 1);
      term.exp = atoi(expPart);
    }

    return in;
  }

  friend std::ostream &operator<<(std::ostream &out, const Term &term)
  {

    if (term.exp == 0)
    {
      if (abs(term.mult) != term.mult)
      {
        out << " " << term.mult;
      }
      else
      {
        out << "+ " << term.mult;
      }
    }
    else
    {
      if (abs(term.mult) != term.mult)
      {
        out << " " << term.mult << "x^" << term.exp;
      }
      else
      {
        out << "+ " << term.mult << "x^" << term.exp;
      }
    }

    return out;
  }

  friend Polynomial operator+(const Polynomial &first, const Polynomial &second);
  friend Polynomial operator*(const Polynomial &first, const Polynomial &second);

  friend std::ostream &operator<<(std::ostream &out, const Polynomial &pol);
};

class Polynomial
{
  Term *poly;
  unsigned degree;
  bool order_ = 0; // 0- по убыванию, 1- пл возрастанию

public:
  // Polynomial():degree(0){
  //   poly= new Term[1];
  //   poly[0] = Term(0,0);
  // }
  // Polynomial(int mult_){
  //   poly = new Term[1];
  //   poly[0] = Term(mult_,0);
  // }

  Polynomial(int mult_ = 0, int exp_ = 0)
  {
    degree = 1;
    poly = new Term[degree];
    poly[0] = Term(mult_, exp_);
  }

  friend Polynomial operator+(const Polynomial &first, const Polynomial &second)
  {
    int exp = 0;
    for (size_t i = 0; i < std::max(first.degree, second.degree); i++)
    {
      exp = std::max(exp, first.poly[i].exp);
      exp = std::max(exp, second.poly[i].exp);
    }

    Polynomial final;
    final.degree = exp + 1;
    final.poly = new Term[final.degree];

    for (size_t i = 0; i < final.degree; i++)
    {
      final.poly[i] = Term(0, i);
    }

    for (size_t i = 0; i < first.degree; i++)
    {
      final.poly[first.poly[i].exp].mult += first.poly[i].mult;
    }

    for (size_t i = 0; i < second.degree; i++)
    {
      final.poly[second.poly[i].exp].mult += second.poly[i].mult;
    }

    return final;
  }

  friend Polynomial operator*(const Polynomial &first, const Polynomial &second)
  {
    Polynomial final;
    final.degree = first.degree * second.degree;
    final.poly = new Term[final.degree];
    for (size_t i = 0; i < first.degree; i++)
    {
      for (size_t j = 0; j < second.degree; j++)
      {
        final.poly[i + first.degree * j].mult = first.poly[i].mult * second.poly[i].mult;
        final.poly[i + first.degree * j].exp = first.poly[i].exp + second.poly[i].exp;
      }
    }
    return final;
  }

  Polynomial &operator+=(const Polynomial &pol)
  {
    Polynomial final = pol + *this;
    *this = final;
    return *this;
  }

  Polynomial &operator*=(const Polynomial &pol)
  {
    Polynomial final = pol * *this;
    *this = final;
    return *this;
  }

  Polynomial(const Polynomial &pol)
  {
    degree = pol.degree;
    poly = new Term[degree];
    for (size_t i = 0; i < degree; i++)
    {
      poly[i] = pol.poly[i];
    }
  }

  Polynomial &operator=(const Polynomial &pol)
  {
    degree = pol.degree;

    delete[] poly;
    poly = new Term[degree];
    for (int i = 0; i < degree; i++)
    {
      poly[i] = pol.poly[i];
    }

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &out, const Polynomial &pol)
  {

    // if (pol.poly[1].mult == abs(pol.poly[1].mult))
    // {
    //   if(pol.poly[1].exp!=0){
    //     out << pol.poly[1].mult << "x^" << pol.poly[1].exp;
    //   }
    //   else{
    //     out << pol.poly[1].mult;
    //   }
    // }
    // else{
    //   out<<pol.poly[1];
    // }

    bool firstTermPrinted = false;

    for (size_t i = 0; i < pol.degree; i++)
    {
      if (!pol.poly[i].mult == 0)
      {
        if (!firstTermPrinted)
        {
          if (pol.poly[i].mult == abs(pol.poly[i].mult))
          {
            if (pol.poly[i].exp != 0)
            {
              out << pol.poly[i].mult << "x^" << pol.poly[i].exp;
            }
            else
            {
              out << pol.poly[i].mult;
            }
          }
          else
          {
            out << pol.poly[i];
          }
          firstTermPrinted = true;
        }

        else
        {
          out << pol.poly[i];
        }
      }
    }
    out << std::endl;
    return out;
  }

 
};
