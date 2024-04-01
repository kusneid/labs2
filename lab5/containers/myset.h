#include <iostream>

#include "myvector.h"

template <typename T>
class MySet : public MyVector<T>
{
private:
  int q_find(const T &el)
  {
    size_t left = 0, right = this->size;
    size_t curIndex = (left + right) / 2;
    while (el != this->pdata[curIndex] && (left < right))
    {
      if (el < this->pdata[curIndex])
      {
        left = curIndex + 1;
      }
      else
      {
        right = curIndex;
      }
      curIndex = (left + right) / 2;
    }
    if (el == this->pdata[curIndex])
    {
      return curIndex;
    }
    return -1;
  }

public:
  MySet(T el = NULL) : MyVector<T>(el){};
  MySet(const T& el) : MyVector(T){

  }
  bool operator==(MySet &s)
  {
    if (this->size != s.size)
    {
      return false;
    }
    for (size_t i = 0; i < this->size; i++)
    {
      if (this->pdata[i] != s[i])
      {
        return false;
      }
    }
    return true;
  }
  MySet &operator+=(MySet &s)
  {
    return *this + s;
  }
  MySet &operator-=(MySet &s)
  {
    return *this - s;
  }
  MySet &operator*=(MySet &s)
  {
    return *this * s;
  }
  void add_element(const T &el)
  {
    if (is_element(el))
    {
      return;
    }

    this->resize();

    int index = this->size; // size++, sort
    for (size_t i = 0; i < this->size; i++)
    {
      if (el < this->pdata[i])
      {
        index = i;
        break;
      }
    }
    this->size++;
    for (size_t i = this->size - 1; i > index; i--)
    {
      this[i] = this[i - 1];
    }
    this[index] = el;
  }
  void delete_element(const T &el)
  {
    int index = q_find(el);
    if (index == -1)
    {
      return;
    }
    this->size--;
    for (size_t i = index; i < this->size; i++)
    {
      this[i] = this[i + 1];
    }
  }
  bool is_element(T el)
  {
    return q_find(el) != -1;
  }
  friend std::ostream &operator<<(std::ostream &out, MySet &s)
  {
    out << '{';
    for (size_t i = 0; i < s.get_size(); i++)
    {
      out << ' ' << s[i];
    }
    out << '}' << std::endl;
    return out;
  }
  friend MySet operator+(MySet &s1, MySet &s2)
  {
    for (size_t i = 0; i < s2.get_size(); i++)
    {
      if (!s1.is_element(s2[i]))
      {
        s1.add_element(s2[i]);
      }
    }
    return s1;
  }
  friend MySet operator-(MySet &s1, MySet &s2)
  {
    for (size_t i = 0; i < s2.get_size(); i++)
    {
      s1.delete_element(s2[i]);
    }
    return s1;
  }
  friend MySet operator*(MySet &s1, MySet &s2)
  {
    for (size_t i = 0; i < s2.get_size(); i++)
    {
      if (!s1.is_element(s2[i]))
      {
        s1.delete_element(s2[i]);
      }
    }
    return s1;
  }
};

// template<>
// class MySet<char*> : MyVector<char*>{
//   private:
//   int q_find(const char* &el)
//   {
//     size_t left = 0, right = this->size;
//     size_t curIndex = (left + right) / 2;
//     while (el != this->pdata[curIndex] && (left < right))
//     {
//       if (el < this->pdata[curIndex])
//       {
//         left = curIndex + 1;
//       }
//       else
//       {
//         right = curIndex;
//       }
//       curIndex = (left + right) / 2;
//     }
//     if (el == this->pdata[curIndex])
//     {
//       return curIndex;
//     }
//     return -1;
//   }

// public:
//   MySet(char *el = NULL) : MyVector<char*>(el){};
//   bool operator==(MySet &s)
//   {
//     if (this->size != s.size)
//     {
//       return false;
//     }
//     for (size_t i = 0; i < this->size; i++)
//     {
//       if (this->pdata[i] != s[i])
//       {
//         return false;
//       }
//     }
//     return true;
//   }
//   MySet operator+=(MySet<char*> &s)
//   {
//     return *this + s;
//   }
//   MySet operator-=(MySet &s)
//   {
//     return *this - s;
//   }
//   MySet operator*=(MySet &s)
//   {
//     return *this * s;
//   }
//   void add_element(const char* el)
//   {
//     if (is_element(el))
//     {
//       return;
//     }
//     if (this->size + 1 >= this->max_size)
//     {
//       this->resize();
//     }
//     int index = this->size; // size++, sort
//     for (size_t i = 0; i < this->size; i++)
//     {
//       if(strcmp(this->pdata[i],el)>0){
//         index = i;
//         break;
//       }
//     }
//     this->size++;
//     for (size_t i = this->size-1; i > index; i--)
//     {
//       strcpy(this->pdata[i], this->pdata[i - 1]);
//     }
//     strcpy(this->pdata[index], el);

//   }
//   void delete_element(const char* el){
//     int index = q_find(el);
//     if(index==-1){
//       return;
//     }
//     this->size--;
//     for (size_t i = index; i < this->size; i++)
//     {
//       //this[i] = this[i+1];
//       strcpy(this->pdata[i], this->pdata[i+1]);
//     }

//   }
//   bool is_element(const char* el)
//   {
//     if (q_find(el) == -1)
//     {
//       return false;
//     }
//     return true;
//   }
//   friend std::ostream &operator<<(std::ostream &out, MySet &s)
//   {
//     out << '{';
//     for (size_t i = 0; i < s.get_size(); i++)
//     {
//       out << ' ' << s[i];
//     }
//     out << '}' << std::endl;
//     return out;
//   }
//   friend MySet operator+(MySet &s1, MySet &s2)
//   {
//     for (size_t i = 0; i < s2.get_size(); i++)
//     {
//       if (!s1.is_element(s2[i]))
//       {
//         s1.add_element(s2[i]);
//       }
//     }
//     return s1;
//   }
//   friend MySet operator-(MySet &s1, MySet &s2)
//   {
//     for (size_t i = 0; i < s2.get_size(); i++)
//     {
//       s1.delete_element(s2[i]);
//     }
//     return s1;
//   }
//   friend MySet operator*(MySet &s1, MySet &s2)
//   {
//     for (size_t i = 0; i < s2.get_size(); i++)
//     {
//       if (!s1.is_element(s2[i]))
//       {
//         s1.delete_element(s2[i]);
//       }
//     }
//     return s1;
//   }
// };

// template <>
// void MySet<char *>::add_element(const char* el)
// {
//   if (is_element(el))
//   {
//     return;
//   }
//   if (this->size + 1 >= this->max_size)
//   {
//     this->resize();
//   }
//   int index = this->size;
//   for (size_t i = 0; i < this->size; i++)
//   {
//     if (strcmp(el, this->pdata[i]) < 0)
//     {
//       index = i;
//       break;
//     }
//   }
//   this->size++;
//   for (size_t i = this->size - 1; i > index; i--)
//   {
//     strcpy(this->pdata[i], this->pdata[i - 1]);
//   }
//   strcpy(this->pdata[index], el);
// }

// template <>
// void MySet<char *>::delete_element(const char *el)
// {
//   int index = q_find(el);
//   if (index == -1)
//   {
//     return;
//   }
//   this->size--;
//   for (size_t i = index; i < this->size; i++)
//   {
//     strcpy(this->pdata[i], this->pdata[i + 1]);
//   }
// }

// template <>
// bool MySet<char *>::is_element(char *el)
// {
//   return q_find(el) != -1;
// }