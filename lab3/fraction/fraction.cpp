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
    if (f.denominator == 0)
    {
        std::cerr << "CAN'T DIVIDE BY ZERO";
    }
    return in;
}

Fraction operator+(const Fraction &f, const int value)
{
    Fraction a(f.denominator * value + f.numerator, f.denominator);
    return a;
}

Fraction operator+(const double value, const Fraction &f)
{
    Fraction a = value;
    return a + f;
}

int Fraction::nod(int a, int b)
{
    return b == 0 ? a : nod(b, a % b);
}

void Fraction::reduceFraction()
{
    int n = nod(numerator, denominator);
    numerator /= n;
    denominator /= n;
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
}

Fraction::Fraction(const int num, const int denom)
{
    numerator = num;
    denominator = denom;
    reduceFraction();
}

Fraction::Fraction(const double value)
{
    double exponenta = std::floor(value);
    double mantissa = value - exponenta;
    int accuracy = 10e6;
    denominator = accuracy;
    numerator = exponenta * denominator + round(mantissa * accuracy);
    reduceFraction();
}

Fraction::Fraction(const char *input)
{
    int spaceIndex = -1, slashIndex = -1, size = strlen(input);
    int wholeNum = 0;
    int newNum = 0, newDenom = 1;

    for (size_t i = 0; i < size; ++i)
    {
        if (input[i] == ' ' && input[i + 1] != ' ')
        {
            spaceIndex = i;
            break;
        }
    }

    if (spaceIndex != -1)
    {
        char wholeNumChar[spaceIndex + 2];
        strncpy(wholeNumChar, input, spaceIndex);
        wholeNumChar[spaceIndex] = '\0';
        wholeNum = atoi(wholeNumChar);
    }

    for (size_t i = spaceIndex + 1; i < size; ++i)
    {
        if (input[i] == '/')
        {
            slashIndex = i;
            break;
        }
    }

    if (slashIndex != -1)
    {
        char numChar[slashIndex - spaceIndex];
        strncpy(numChar, input + spaceIndex + 1, slashIndex - spaceIndex - 1);
        numChar[slashIndex - spaceIndex - 1] = '\0';

        char denomChar[size - slashIndex];
        strncpy(denomChar, input + slashIndex + 1, size - slashIndex - 1);
        denomChar[size - slashIndex - 1] = '\0';

        newNum = atoi(numChar);
        newDenom = atoi(denomChar);
    }
    else
    {
        newNum = atoi(input);
        denominator = 1;
    }

    newNum = wholeNum * newDenom + (wholeNum < 0 ? -newNum : newNum);
    numerator = newNum;
    denominator = newDenom;

    reduceFraction();
}

Fraction Fraction::operator+(const int &num)
{
    return Fraction{numerator + num * denominator, denominator};
}

Fraction Fraction::operator+(const Fraction &value)
{
    int newDenom = denominator * value.denominator;
    int newNum = numerator * value.denominator + value.numerator * denominator;
    return Fraction(newNum, newDenom);
}

Fraction Fraction::operator+(const double value)
{
    Fraction a = value;
    return a + *this;
}

Fraction &Fraction::operator+=(const Fraction &value)
{
    Fraction a = *this + value;
    return *this = a;
}

Fraction &Fraction::operator+=(const int value)
{
    Fraction a = *this + value;
    return *this = a;
}

Fraction &Fraction::operator+=(const double value)
{
    Fraction a = *this + value;
    return *this = a;
}