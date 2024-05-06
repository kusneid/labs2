#include "polynom.h"

Term operator+(const Term &f, const Term &s)
{
  if (s.mult == 0)
  {
    return f;
  }
  else if (f.mult == 0)
  {
    return s;
  }

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

std::istream &operator>>(std::istream &in, Term &term)
{
  char input[TERM_INPUT];
  in.getline(input, TERM_INPUT);
  char finalws[TERM_INPUT];
  int finalIndex = 0;

  for (size_t i = 0; input[i] != '\0'; ++i)
  {
    if (input[i] != ' ')
    {
      finalws[finalIndex++] = input[i];
    }
  }
  finalws[finalIndex] = '\0';

  term.mult = 0;
  term.exp = 0;
  unsigned len = strlen(finalws);
  int xIndex = -1;
  int stIndex = -1;

  for (size_t i = 0; i < len; ++i)
  {
    if (finalws[i] == 'x')
    {
      xIndex = i;
      break;
    }
  }

  if (xIndex != -1)
  {
    for (size_t i = xIndex + 1; i < len; ++i)
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
  else if (xIndex == 0 || (xIndex == 1 && (finalws[0] == '-' || finalws[0] == '+')))
  {
    term.mult = (finalws[0] == '-') ? -1 : 1;
  }
  else
  {
    char coeffPart[TERM_INPUT];
    strncpy(coeffPart, finalws, xIndex);
    coeffPart[xIndex] = '\0';
    term.mult = atoi(coeffPart);
  }

  if (xIndex != -1 && stIndex == -1)
  {
    term.exp = 1;
  }
  else if (stIndex != -1)
  {
    char expPart[TERM_INPUT];
    strcpy(expPart, finalws + stIndex + 1);
    term.exp = atoi(expPart);
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, const Term &term)
{
  if (term.exp == 0)
  {
    out << term.mult;
  }
  else
  {
    if (term.mult == -1)
    {
      out << "-x";
    }
    else if (term.mult < 0)
    {
      out << term.mult << "x";
    }
    else if (term.mult == 1)
    {
      out << "x";
    }
    else
    {
      out << term.mult << "x";
    }

    if (term.exp != 1)
    {
      out << "^" << term.exp;
    }
  }

  return out;
}

Polynomial operator+(const Polynomial &first, const Polynomial &second)
{
  Polynomial final;
  final.poly = new Term[first.degree + second.degree];
  int i1 = 0, i2 = 0, i = 0;
  while (i1 < first.degree && i2 < second.degree)
  {
    if (first.poly[i1].exp < second.poly[i2].exp)
    {
      final.poly[i++] = first.poly[i1++];
    }
    else if (first.poly[i1].exp == second.poly[i2].exp)
    {
      final.poly[i++] = first.poly[i1++] + second.poly[i2++];
    }
    else
    {
      final.poly[i++] = second.poly[i2++];
    }
  }
  while (i1 < first.degree)
  {

    final.poly[i++] = first.poly[i1++];
  }
  while (i2 < second.degree)
  {
    final.poly[i++] = second.poly[i2++];
  }
  final.degree = i;
  return final;
}

Polynomial operator*(const Polynomial &first, const Polynomial &second)
{
  Polynomial final;
  for (int i = 0; i < first.degree; i++)
  {
    for (int j = 0; j < second.degree; j++)
    {
      final += Polynomial(first.poly[i].mult * second.poly[j].mult, first.poly[i].exp + second.poly[j].exp);
    }
  }
  return final;
}

Polynomial &Polynomial::operator+=(const Polynomial &pol)
{
  Polynomial final = pol + *this;
  *this = final;
  return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &pol)
{
  Polynomial final = pol * *this;
  *this = final;
  return *this;
}

Polynomial::Polynomial(const Polynomial &pol)
{
  degree = pol.degree;
  poly = new Term[degree];
  for (size_t i = 0; i < degree; i++)
  {
    poly[i] = pol.poly[i];
  }
}

Polynomial &Polynomial::operator=(const Polynomial &pol)
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

std::ostream &operator<<(std::ostream &out, const Polynomial &pol)
{
  bool first = true;
  if (pol.order_)
  {
    for (int i = 0; i < pol.degree; ++i)
    {
      if (pol.poly[i].mult != 0)
      {
        if (!first && pol.poly[i].mult > 0)
          out << " + ";
        out << pol.poly[i];
        first = false;
      }
    }
  }
  else
  {
    for (int i = pol.degree - 1; i >= 0; --i)
    {
      if (pol.poly[i].mult != 0)
      {
        if (!first && pol.poly[i].mult > 0)
          out << " + ";
        out << pol.poly[i];
        first = false;
      }
    }
  }
  if (first)
    out << "0";
  return out;
}

std::istream &operator>>(std::istream &in, Polynomial &pol)
{
  char input[POLYNOM_INPUT];
  in.getline(input, POLYNOM_INPUT); // ввод полинома

  char finalws[POLYNOM_INPUT];
  unsigned finalIndex = 0;
  for (size_t i = 0; input[i] != '\0'; ++i) // удаление пробелов
  {
    if (input[i] != ' ')
    {
      finalws[finalIndex++] = input[i];
    }
  }
  finalws[finalIndex] = '\0';

  int startIndex = 0;
  int termIndex = 0;
  char termString[TERM_INPUT]; // текущий терм для обработки
  char coeffPart[TERM_INPUT];  // его коэффицент
  char expPart[TERM_INPUT];    // его степень
  Term term;

  for (unsigned i = 0; i < strlen(finalws) + 1; ++i)
  {
    if (finalws[i] == '+' || finalws[i] == '-' || finalws[i] == '\0') // ищем либо знак первого терма, либо, при отсутствии знака у первого терма ищем знак у второго и кидаем все что от 0 до i
    {
      strncpy(termString, finalws + startIndex, i - startIndex);
      termString[i - startIndex] = '\0';
      // далее обрабатываем терм
      int xIndex = -1;
      int expIndex = -1;
      for (int j = 0; termString[j] != '\0'; ++j)
      {
        if (termString[j] == 'x')
        {
          xIndex = j;
          break;
        }
      }

      term.exp = 0;
      term.mult = 0;
      if (xIndex == -1) // х не найден соответственно степень нулевая и искать ее нет смысла
      {
        term.mult = atoi(termString);
      }
      else
      {
        if (xIndex == 0 || (xIndex == 1 && (termString[0] == '-' || termString[0] == '+'))) // если нет коэффицента
        {
          term.mult = (termString[0] == '-') ? -1 : 1;
        }
        else
        {
          strncpy(coeffPart, termString, xIndex);
          coeffPart[xIndex] = '\0';
          term.mult = atoi(coeffPart);
        }

        for (int j = xIndex + 1; termString[j] != '\0'; ++j) // поиск степени
        {
          if (termString[j] == '^')
          {
            expIndex = j;
            break;
          }
        }

        if (expIndex == -1)
        {
          term.exp = 1;
        }
        else
        {
          strncpy(expPart, termString + expIndex + 1, strlen(termString) - expIndex - 1);
          expPart[strlen(termString) - expIndex - 1] = '\0';
          term.exp = atoi(expPart);
        }
      }

      pol += Polynomial(term.mult, term.exp);
      startIndex = i;
    }
  }
  return in;
}

Term::Term(int mult, int exp) : mult(mult), exp(exp) {}

Polynomial::Polynomial(int mult_, int exp_)
{
  degree = 1;
  poly = new Term[degree];
  poly[0] = Term(mult_, exp_);
}