#pragma once

#include <iostream>
#include <cstring>

const int MAX_SIZE = 4;

template <typename T>
class MyVector
{
protected:
    int max_size;
    int size;
    T *pdata;

    void resize()
    {
        if (size >= max_size)
        {
            max_size *= 2;
        }
        else if (size < max_size / 4 && max_size / 2 >= 8)
        {
            max_size /= 2;
        }
        else
        {
            return;
        }
        T *newData = new T[max_size];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = pdata[i];
        }
        delete[] pdata;
        pdata = newData;
    }

public:
    MyVector()
    {
        max_size = MAX_SIZE;
        size = 0;
        pdata = new T[max_size];
    }
    MyVector(T el, int max_size = MAX_SIZE)
    {
        this->max_size = max_size;
        size = 0;
        pdata = new T[max_size];
        if (el)
        {
            add_element(el);
        }
    }
    MyVector(const MyVector &v)
    {
        max_size = v.max_size;
        size = v.size;
        pdata = new T[max_size];
        for (size_t i = 0; i < size; i++)
        {
            pdata[i] = v.pdata[i];
        }
    }
    ~MyVector()
    {
        delete[] pdata;
    }
    void add_element(T el)
    {
        resize();
        pdata[size++] = el;
    }
    bool delete_element(int i)
    {
        if (i < 0 || i >= size)
        {
            return false;
        }
        
        delete pdata[i];
        for (int j = i + 1; j < size; j++)
        {
            pdata[j - 1] = pdata[j];
        }
        
        size--;
        resize();
        return true;
    }
    T &operator[](int i) const
    {
        if (i < 0 || i >= size)
        {
            std::cout << "\nwrong index, 0 index will be returned\n";
            return pdata[0];
        }
        return pdata[i];
    }
    void sort()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (pdata[i] > pdata[j])
                {
                    std::swap(pdata[i], pdata[j]);
                }
            }
        }
    }
    int get_size() const { return size; }
    int get_max_size() const { return max_size; }
    int find(T el) const
    {
        for (size_t i = 0; i < size; i++)
        {
            if (compare(el, pdata[i]) == 0)
            {
                return i;
            }
        }
        return -1;
    }
    MyVector &operator=(const MyVector &v)
    {
        if(this == &v){return *this;}
        delete[] pdata;
        pdata = new T[v.max_size];
        size = 0;
        max_size = v.max_size;
        for (int i = 0; i < v.size; i++)
        {
            add_element(v.pdata[i]);
        }
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const MyVector &v)
    {
        out << '{';
        for (size_t i = 0; i < v.size; i++)
        {
            out << ' ' << v[i];
        }
        out << '}' << '\n';
        return out;
    }
};
//------------------------------------------------------------------------------
template <>
MyVector<char *>::MyVector(const MyVector &v)
{
    max_size = v.max_size;
    size = v.size;
    pdata = new char *[max_size];
    for (size_t i = 0; i < size; i++)
    {
        pdata[i] = new char[strlen(v.pdata[i]) + 1];
        strcpy(pdata[i], v.pdata[i]);
    }
}

template <>
MyVector<char *>::~MyVector()
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] pdata[i];
    }
    delete[] pdata;
}

template <>
void MyVector<char *>::add_element(char *el)
{
    resize();
    pdata[size] = new char[strlen(el) + 1];
    strcpy(pdata[size], el);
    size++;
}

template <>
MyVector<char *>::MyVector(char *el, int maxsize) : pdata(nullptr), size(0), max_size(maxsize > MAX_SIZE ? maxsize : MAX_SIZE)
{
    pdata = new char *[max_size];
    add_element(el);
}

template <>
bool MyVector<char *>::delete_element(int i)
{
    if (i < 0 || i >= size)
    {
        return false;
    }
    
    delete[] pdata[i]; //!!!!!!!тут исправление
    for (int j = i + 1; j < size; j++)
    {
        pdata[j - 1] = pdata[j];
    }
    
    size--;
    resize();
    return true;
}

template <>
MyVector<char *> &MyVector<char *>::operator=(const MyVector &v)
{
    if(this == &v){return *this;}
    for (int i = 0; i < size; i++)
    {
        delete[] pdata[i];
    }
    delete[] pdata;
    pdata = new char *[v.max_size];
    size = 0;
    max_size = v.max_size;
    for (int i = 0; i < v.size; i++)
    {
        add_element(v.pdata[i]);
    }
    return *this;
}

template <>
void MyVector<char *>::sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(pdata[i],pdata[j])>0)
            {
                std::swap(pdata[i], pdata[j]);
            }
        }
    }
}