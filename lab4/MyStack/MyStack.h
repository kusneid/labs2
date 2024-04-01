#pragma once

template <class INF, class FRIEND>
class ListNode
{
private:
    INF d;
    ListNode *next;
    ListNode(void) { next = nullptr; }
    friend FRIEND;

    ListNode(INF a)
    {
        d = a;
        next = nullptr;
    }

    INF getValue() { return d; }
};

template <class INF>
class MyStack
{
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;

public:
    bool empty(void)
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }

    MyStack(void)
    {
        top = nullptr;
    }

    ~MyStack(void)
    {
        Node *temp;
        while (top)
        {
            temp = top->next;
            delete top;
            top = temp;
        }
    }

    bool push(INF n)
    {
        Node *new_top = new Node(n);
        new_top->next = top;
        top = new_top;
        return 0;
    }

    bool pop(void)
    {
        if (empty())
        {
            return false;
        }
        Node *temp = top->next;
        delete top;
        top = temp;
        return true;
    }

    INF top_inf(void) const
    {
        return top->getValue();
    }

    MyStack(const MyStack &s)
    {
        Node *newNode = s.top;
        MyStack rightStack;
        while (newNode)
        {
            rightStack.push(newNode->getValue());
            newNode = newNode->next;
        }
        top = nullptr;
        while (!rightStack.empty())
        {
            push(rightStack.top_inf());
            rightStack.pop();
        }
    }

    MyStack &operator=(const MyStack &s)
    {
        if (this != &s)
        {

            Node *temp;//очищение стэка, то же самое что и в деструкторе
            while (top)
            {
                temp = top->next;
                delete top;
                top = temp;
            }

            Node *newNode = s.top;
            MyStack rightStack;
            while (newNode)
            {
                rightStack.push(newNode->getValue());
                newNode = newNode->next;
            }
            top = nullptr;
            while (!rightStack.empty())
            {
                pop();
                push(rightStack.top_inf());
                rightStack.pop();
            }
        }
        return *this;
    }
};