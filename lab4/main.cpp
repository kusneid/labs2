#include "MyStack/MyStack.h"
#include <iostream>

void Multipliers(int n, MyStack<int> &stack)
{
    int i = 2, currentN = 1;
    if (n < 1)
    {
        return;
    }
    if (n == 1)
    {
        stack.push(1);
        return;
    }
    while (currentN < n)
    {
        if ((n / currentN) % i == 0)
        {
            currentN *= i;
            stack.push(i);
        }
        else
        {
            i += 1;
        }
    }
}

int main()
{
    MyStack<int> stack;

    MyStack<int> stackReversed;
    int value = 467803133;
    Multipliers(value, stack);
    // MyStack<int> a(stack);
    // a = stack;
    std::cout << value << " = ";
    while (!stack.empty())
    {
        std::cout << stack.top_inf();
        stackReversed.push(stack.top_inf());
        stack.pop();
        if (!stack.empty())
            std::cout << " * ";
    }
    std::cout << "\n"
              << value << " = ";
    while (!stackReversed.empty())
    {
        std::cout << stackReversed.top_inf();
        stackReversed.pop();
        if (!stackReversed.empty())
            std::cout << " * ";
    }
    return 0;
}
