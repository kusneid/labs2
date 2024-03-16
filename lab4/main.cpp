#include "MyStack.h"
#include <iostream>

void Multipliers(int n, MyStack<int> &stack){
    int i = 2, currentN = 1;
    if (n < 1) {
        return;
    }
    
    while (currentN < n) {
        if ((n / currentN) % i == 0) {
            currentN *= i;
            stack.push(i);
            
        }
        else {
            
            i += 1;
        }
    }
}

int main(){
    MyStack<int> stack;
    MyStack<int> stackReversed;

    
    int n;
    std::cin>>n;
    Multipliers(n,stack);
    MyStack<int> a(stack);
    //a = stack;
    std::cout << n << " = ";
    int last=0;
    int curSt = 1;
    while (!a.empty()) {
        if(last == a.top_inf()){
            curSt++;

        }
        else{
            if(last!=0){
                std::cout << last<<"^"<<curSt<<'*';
            }
            
            
            
            last = a.top_inf();
            curSt=1;
            
        }
        a.pop();
        
    }
    std::cout << last<<"^"<<curSt;
    
    std::cout << "\n" << n << " = ";
    while (!stackReversed.empty()) {
        std::cout << stackReversed.top_inf();
        stackReversed.pop();
        if (!stackReversed.empty()) std::cout << " * ";
    }

    // stackReversed = stack;
    // std::cout<<"\nstackreversed is stack now\n";
    // while (!stackReversed.empty()) {
    //     std::cout << stackReversed.top_inf();
    //     //stackReversed.pop();
    // }

    // MyStack<int> lol(stackReversed);
    // std::cout<<"\nstack lol initializied with stackreversed\n";
    // while (!lol.empty()) {
    //     std::cout << lol.top_inf();
    //     lol.pop();
    // }
    
    
    return 0;
}


