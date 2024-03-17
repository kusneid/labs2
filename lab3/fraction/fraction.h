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

    int nod(int a, int b);
   
    void reduceFraction();
    

public:
    Fraction(const int num = 0, const int denom = 1);
    
    Fraction(const double value);
 
    Fraction(const char *input);
    
    Fraction operator+(const int &num);
    
    Fraction operator+(const Fraction &value);
  
    Fraction operator+(const double value);
  
    Fraction &operator+=(const Fraction &value);
    
    Fraction &operator+=(const int value);
    
    Fraction &operator+=(const double value);
    

    friend Fraction operator+(const Fraction &f, const int value);
    friend Fraction operator+(const double value, const Fraction &f);
};

std::ostream &operator<<(std::ostream &out, Fraction &f);
std::istream &operator>>(std::istream &in, Fraction &f);
