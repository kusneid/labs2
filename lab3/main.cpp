#include "Fraction.h"
int interactive(){
    // ввод дроби с клавиатуры
    std::cout << "Enter Fraction values: \n";
    Fraction z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;
    // проверка конструкторов
    Fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    Fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    Fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    Fraction f = dbl;
    std::cout << "f=" << f << std::endl;
    // проверка перегруженной операции "+"
    //std::cout<<"heue\n";
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;//vsrreg
    f += (dbl / 2);
    std::cout << "f=" << f << std::endl;
    //std::cout<<x<<"\n";
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
     //std::cout << "x= " << x << std::endl;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    //std::cout << "x= " << x << std::endl;

    std::cout << "y=" << y << std::endl;
    //std::cout<<y<<" "<<dbl<<" "<<" "<<x<<" "<<i<<"\n";
    y += dbl  + x + i;
    std::cout << "y=" << y << std::endl;
    return 0;
}

int demo(){
    // ввод дроби с клавиатуры
    std::cout << "Fraction z equals -1 23/467 \n";
    Fraction z{"-1 23/467"};
    std::cout << "z=" << z << std::endl;
    // проверка конструкторов
    Fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    Fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    Fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    Fraction f = dbl;
    std::cout << "f=" << f << std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
    return 0;
}
int main(int argc, char *argv[]) {
    system("chcp 1251");

    bool isInteractive = false;    // по умолчанию демо-режим.

    // Если i передается в качестве аргумента, то программу
    // необходимо запустить в интерактивном режиме
    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive) {
        return interactive();

    } else {
        return demo();
    }
}