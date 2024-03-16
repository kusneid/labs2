#pragma once

#include <iostream>
#include <cstring>

const int MAX_SIZE = 8;

class MyVector
{
protected:
    int max_size;
    int size;
    char **pdata;

    void resize();
    void CopyVector(const MyVector &v);
    

public:
    MyVector(char *el = nullptr, int max_size = MAX_SIZE)
    {
        this->max_size = max_size;
        this->add_element(el);
    };
    MyVector(const MyVector &v);//copy
    ~MyVector();
    void add_element(char *el);
    bool delete_element(int i);
    char *operator[](int i);
    void sort();
    int get_size() { return size; }
    int get_max_size() { return max_size; }
    int find(char *el);
    MyVector &operator=(MyVector &v);
    friend std::ostream &operator<<(std::ostream &out, MyVector &v);

};
