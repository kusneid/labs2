#include <iostream>

#include "myvector.h"

template <typename T>
class MySet : public MyVector<T>
{
private:
  int q_find(const T &el)
  {

    size_t left = 0, right = this->size;
    while (left < right)
    {
      size_t mid = left + (right - left) / 2;
      if (this->pdata[mid] < el)
      {
        left = mid + 1;
      }
      else if (this->pdata[mid] > el)
      {
        right = mid;
      }
      else
      {
        return mid;
      }
    }
    return -1;
  }

public:
  using MyVector<T>::max_size;
  using MyVector<T>::size;
  using MyVector<T>::pdata;
  MySet(const T &el) : MyVector<T>(el) {}
  MySet() : MyVector<T>() {}

  bool operator==(MySet &s)
  {
    if (size != s.size)
    {
      return false;
    }
    for (size_t i = 0; i < size; i++)
    {
      if (pdata[i] != s.pdata[i])
      {
        return false;
      }
    }
    return true;
  }
  MySet &operator+=(MySet &s)
  {
    *this = *this + s;
    return *this;
  }
  MySet &operator-=(MySet &s)
  {
    *this = *this - s;
    return *this;
  }
  MySet &operator*=(MySet &s)
  {
    *this = *this * s;
    return *this;
  }

  void add_element(const T &el)
  {
    if (is_element(el))
    {
      return;
    }
    this->resize();
    size++;
    int ind = 0;
    while ((ind < size - 1) && (pdata[ind] < el))
    {
      ind++;
    }
    for (int i = size - 1; i > ind; i--)
    {
      pdata[i] = pdata[i - 1];
    }
    pdata[ind] = el;
  }
  void delete_element(const T &el)
  {
    int index = q_find(el);
    if (index == -1)
    {
      return;
    }
    delete pdata[index];
    for (size_t i = index; i < this->size; i++)
    {
      pdata[i] = pdata[i + 1];
    }
    this->size--;
    pdata[size] = nullptr;
  }
  bool is_element(const T &el)
  {
    return q_find(el) != -1;
  }
  friend std::ostream &operator<<(std::ostream &out, const MySet &s)
  {
    out << '{';
    for (size_t i = 0; i < s.get_size(); i++)
    {
      out << ' ' << s[i];
    }
    out << '}' << std::endl;
    return out;
  }
  friend MySet operator+(const MySet &s1, const MySet &s2)
  {
    MySet s3(s1);
    for (size_t i = 0; i < s2.get_size(); i++)
    {
      if (!s3.is_element(s2[i]))
      {
        s3.add_element(s2[i]);
      }
    }
    return s3;
  }
  friend MySet operator-(const MySet &s1, const MySet &s2)
  {
    MySet s3(s1);

    for (size_t i = 0; i < s2.get_size(); i++)
    {
      if (s3.is_element(s2[i]))
      {
        s3.delete_element(s2[i]);
      }
    }
    return s3;
  }
  friend MySet operator*(const MySet &s1, const MySet &s2)
  {
    MySet s3(s1);
    for (size_t i = 0; i < s2.get_size(); i++)
    {
      if (!s3.is_element(s2[i]))
      {
        s3.delete_element(s2[i]);
      }
    }
    return s3;
  }
  MySet &operator=(const MySet &el)
  {
    delete[] pdata;
    pdata = new T[el.max_size];
    size = 0;
    max_size = el.max_size;
    for (int i = 0; i < el.size; i++)
    {
      add_element(el.pdata[i]);
    }
    return *this;
  }
};
//--------------------------------------------------------------------------
template <>
int MySet<char *>::q_find(char *const &el)
{

  size_t left = 0, right = this->size;
  while (left < right)
  {
    size_t mid = left + (right - left) / 2;
    if (strcmp(this->pdata[mid], el) < 0)
    {
      left = mid + 1;
    }
    else if (strcmp(this->pdata[mid], el) > 0)
    {
      right = mid;
    }
    else
    {
      return mid;
    }
  }

  return -1;
}

template <>
void MySet<char *>::add_element(char *const &el)
{
  if (is_element(el))
  {
    return;
  }
  this->resize();
  size++;
  int ind = 0;
  while ((ind < size - 1) && (strcmp(pdata[ind], el) < 0))
  {
    ind++;
  }
  for (int i = size - 1; i > ind; i--)
  {
    pdata[i] = pdata[i - 1];
  }
  pdata[ind] = new char[strlen(el) + 1];
  strcpy(pdata[ind], el);
}

template <>

void MySet<char *>::delete_element(char *const &el)
{
  int index = q_find(el);
  if (index == -1)
  {
    return;
  }
  delete[] pdata[index];
  for (size_t i = index; i < this->size; i++)
  {
    pdata[i] = pdata[i + 1];
  }
  this->size--;
  pdata[size] = nullptr;
}
template <>
bool MySet<char *>::operator==(MySet &s)
{
  if (this->size != s.size)
  {
    return false;
  }
  for (size_t i = 0; i < this->size; i++)
  {
    if (strcmp(this->pdata[i], s.pdata[i]) != 0)
    {
      return false;
    }
  }
  return true;
}