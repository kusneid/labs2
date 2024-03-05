#include "MyStack.h"
#include <iostream>

// void Multipliers(int n, MyStack<int> &stack){
//     int i = 2, currentN = 1;
//     if (n < 1) {
//         return;
//     }
//     if (n == 1) {
//         stack.push(1);
//         return;
//     }
//     while (currentN < n) {
//         if ((n / currentN) % i == 0) {
//             currentN *= i;
//             stack.push(i);
//         }
//         else {
//             i += 1;
//         }
//     }
// }

// int main(){
//     MyStack<int> stack;
//     MyStack<int> stackReversed;
//     Multipliers(3960,stack);
//     std::cout << 3960 << " = ";
//     while (!stack.empty()) {
//         std::cout << stack.top_inf();
//         stackReversed.push(stack.top_inf());
//         stack.pop();
//         if (!stack.empty()) std::cout << " * ";
//     }
//     std::cout << "\n" << 3960 << " = ";
//     while (!stackReversed.empty()) {
//         std::cout << stackReversed.top_inf();
//         stackReversed.pop();
//         if (!stackReversed.empty()) std::cout << " * ";
//     }
//     return 0;
// }

#include "MyStack/MyStack.h"
#include <iostream>


void multipliers(int n, MyStack<int> &stack) {
    int i = 2, cur = 1;
    if (n < 1) return;
    if (n == 1) {
        stack.push(1);
        return;
    }
    while (cur < n) {
        if ((n / cur) % i == 0) {
            cur *= i;
            stack.push(i);
        }
        else {
            i += 1;
        }
    }
}

int main() {
    MyStack<int> stack, stack2;
    int n = 3960;
    multipliers(n, stack);
    std::cout << n << " = ";
    while (!stack.empty()) {
        std::cout << stack.top_inf();
        stack2.push(stack.top_inf());
        stack.pop();
        if (!stack.empty()) std::cout << " * ";
    }
    std::cout << "\n" << n << " = ";
    while (!stack2.empty()) {
        std::cout << stack2.top_inf();
        stack2.pop();
        if (!stack2.empty()) std::cout << " * ";
    }
    return 0;
}
