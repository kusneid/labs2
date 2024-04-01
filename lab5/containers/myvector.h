#pragma once

#include <iostream>
#include <cstring>

const int MAX_SIZE = 8;

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
        T *newData = new T[max_size];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = pdata[i];
            delete pdata[i];
        }
        delete[] pdata;
        pdata = newData;
    }
    void CopyVector(const MyVector &v)
    {
        max_size = v.max_size;
        size = v.size;
        T *newData = new T[max_size];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = v[i];
        }
        pdata = newData;
    }

public:
    MyVector(T el = nullptr, int max_size = MAX_SIZE)
    {
        max_size = max_size;
        add_element(el);
    }
    MyVector(const MyVector &v)
    {
        CopyVector(v);
    }
    ~MyVector()
    {
        for (size_t i = 0; i < size; i++)
        {
            delete pdata[i];
        }
        delete pdata;
    }
    void add_element(T el)
    {
        if (size + 1 >= max_size)
        {
            resize();
        }
        pdata[size++] = el;
        sort();
        return;
    }
    bool delete_element(int i)
    {
        if (pdata[i] != nullptr)
        {
            delete pdata[i];
            size--;
        }
        else
        {
            std::cout << "\nCAN'T FIND ELEMENT BY INDEX" << i << '\n';
            return 1;
        }

        return 0;
    }
    T &operator[](int i)
    {
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
    int get_size() { return size; }
    int get_max_size() { return max_size; }
    int find(T el)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (pdata[i] == el)
            {
                return i;
            }
        }
        return -1;
    }
    MyVector &operator=(const MyVector &v)
    {
        CopyVector(v);
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, MyVector &v)
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
void MyVector<char *>::resize()
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
    char **newData = new char *[max_size];
    for (size_t i = 0; i < size; i++)
    {
        newData[i] = new char[strlen(pdata[i]) + 1];
        strcpy(newData[i], pdata[i]);
        delete[] pdata[i];
    }
    delete[] pdata;
    pdata = newData;
}

template <>
void MyVector<char *>::CopyVector(const MyVector<char *> &v)
{
    pdata = new char *[v.max_size];
    size = v.size;
    max_size = v.max_size;
    for (int i = 0; i < v.size; i++)
    {
        pdata[i] = new char[strlen(v.pdata[i]) + 1];
        strcpy(pdata[i], v.pdata[i]);
    }
}

template <>
void MyVector<char *>::sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(pdata[i], pdata[j]) > 0)
            {
                std::swap(pdata[i], pdata[j]);
            }
        }
    }
}

template <>
void MyVector<char *>::add_element(char *el)
{

    resize();

    pdata[size] = new char[strlen(el) + 1];
    strcpy(pdata[size], el);
    size++;
    sort();
    return;
}

template <>
MyVector<char *>::MyVector(char *el, int maxsize) : pdata(nullptr), size(0), max_size(maxsize > MAX_SIZE ? maxsize : MAX_SIZE)
{
    pdata = new char *[max_size];
    if (el != nullptr)
    {
        add_element(el);
    }
}

template <>
MyVector<char *>::MyVector(const MyVector &v)
{
    CopyVector(v);
}

template <>
MyVector<char *>::~MyVector()
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] pdata[i];
    }
    delete pdata;
}

template <>
bool MyVector<char *>::delete_element(int i)
{
    if (i < 0 || i >= size)
    {
        std::cout << "\nINVALID INDEX" << i << '\n';
        return false;
    }
    delete[] pdata[i];
    for (int j = i + 1; j < size; j++)
    {
        pdata[j - 1] = pdata[j];
    }
    size--;
    resize();

    if (size == 0)
    {
        delete[] pdata;
        pdata = nullptr;
    }

    return true;
}

// sort?
template <>
int MyVector<char *>::find(char *el)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(pdata[i], el) == 0)
        {
            return i;
        }
    }
    return -1;
}
