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
        return (!top);
    }

    MyStack(void)
    {
        top = new Node;
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
        if (empty()){
            return false;
        }
        Node *temp = top->next;
        delete top;
        top = temp;
        return 0;
    }

    INF top_inf(void)
    {
        return top->getValue();
    }
};