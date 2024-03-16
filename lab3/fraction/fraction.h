#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>


class Fraction
{
    friend std::ostream &operator<<(std::ostream &out, Fraction &f);
    friend std::istream &operator>>(std::istream &in, Fraction &f);

    int numerator;
    int denominator;

    int nod(int a, int b)
    {
        return b == 0 ? a : nod(b, a % b);
    }
 void reduceFraction()
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
public:
   
    Fraction(const int num = 0, const int denom = 1)
    {
        numerator = num;
        denominator = denom;
        reduceFraction();
    }

    Fraction(double value)
    {
        double exponenta = std::floor(value);
        double mantissa = value - exponenta;
        int accuracy = 10e6;
        denominator = accuracy;
        numerator = exponenta * denominator + round(mantissa * accuracy);
        reduceFraction();
    }

    Fraction(const char *input)
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
        else{
            newNum = atoi(input);
            denominator = 1;
        }

        newNum = wholeNum * newDenom + (wholeNum < 0 ? -newNum : newNum);
        numerator = newNum;
        denominator = newDenom;

        reduceFraction();
    }

    Fraction operator+(const int& num)
    {
        //std::cout<<"ya tut"<< this->numerator<<' '<<this->denominator<<std::endl;
       // Fraction a ();
        return Fraction{numerator + num * denominator, denominator};
    }

    Fraction operator+(const Fraction& value)
    {
        //value.reduceFraction();
        // if (denominator == value.denominator)
        // {
        //     numerator += value.numerator;
        // }
        // else
        // {
        //     int k = nod(denominator, value.denominator);
        //     int oldDen = denominator;
        //     denominator = (denominator / k) * value.denominator;
        //     numerator = (numerator / k) * value.denominator;
        //     // std::cout<<numerator;
        //     value.numerator = (value.numerator / k) * oldDen;
        //     // std::cout<<value.getnum();
        //     numerator += value.numerator;
        // }
        
        int newDenom = denominator * value.denominator;
        int newNum = numerator * value.denominator + value.numerator * denominator;
        return Fraction(newNum,newDenom);

        
    }

    Fraction operator+(const double value)
    {
        reduceFraction();
        Fraction a = value;
        a.reduceFraction();
        return a + *this;
    }

    Fraction& operator+=(const Fraction& value) 
    {
         Fraction a = *this + value;
         a.reduceFraction();
        return *this=a;
    }

    Fraction& operator+=(const int value)
    {
        Fraction a = *this + value;
        a.reduceFraction();
        return *this=a;
        
    }

    Fraction& operator+=(const double value)
    {
        Fraction a = *this + value;
        a.reduceFraction();
        return *this=a;
    }

    friend Fraction operator+(const Fraction& f, const int value);
    friend Fraction operator+(const double value,const Fraction& f);
};

std::ostream &operator<<(std::ostream &out, Fraction &f);
std::istream &operator>>(std::istream &in, Fraction &f);
