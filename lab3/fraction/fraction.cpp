#include "fraction.h"

std::ostream &operator<<(std::ostream &out, Fraction &f)
{
    if (f.numerator == 0)
    {
        out << 0;
        return out;
    }
    f.reduceFraction();
    if (f.denominator == 1)
    {
        out << f.numerator;
        return out;
    }
    if (abs(f.numerator) > f.denominator)
    {

        int num = f.numerator / f.denominator;
        if (f.numerator - num * f.denominator == 0)
        {
            out << num;
            return out;
        }
        out << num << ' ' << abs(f.numerator - num * f.denominator) << '/' << f.denominator;
    }
    else
    {
        out << f.numerator << '/' << f.denominator;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &f)
{
    char str[50];
    in.getline(str, 50);
    f = str;
    f.reduceFraction();
    return in;
}

Fraction operator+(int value, Fraction f){
    Fraction a = {f.denominator*value+f.numerator,f.denominator};
    a.reduceFraction();
    return a;
}

Fraction operator+(double value, Fraction f){
    Fraction a = value;
    a.reduceFraction();
    return a + f;
}