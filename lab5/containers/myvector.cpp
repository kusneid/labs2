#include "myvector.h"

void MyVector::resize()
{
  if (size >= max_size)
  {
    max_size *= 2;
  }
  else if (size < max_size / 4 && max_size / 2 >= 8)
  {
    max_size /= 2;
  }
  char **newData = new char *[max_size];
  for (size_t i = 0; i < size; i++)
  {
    newData[i] = new char[strlen(pdata[i] + 1)];
    strcpy(newData[i], pdata[i]);
    delete[] pdata[i];
  }
  delete[] pdata;
  pdata = newData;
}

void MyVector::CopyVector(const MyVector &v)
{
  this->max_size = v.max_size;
  this->size = v.size;
  char **newData = new char *[max_size];
  for (size_t i = 0; i < size; i++)
  {
    newData[i] = new char[strlen(pdata[i] + 1)];
    strcpy(newData[i], pdata[i]);
  }
  pdata = newData;
}


MyVector::MyVector(const MyVector &v){
  CopyVector(v);
}

MyVector::~MyVector(){
  for (size_t i = 0; i < size; i++)
  {
    delete[] pdata[i];
  }
  delete pdata;
}

void MyVector::add_element(char* el){
  if (size+1>=max_size)
  {
    resize();
  }
  pdata[size++] = el;
  sort();
  return;
}

bool MyVector::delete_element(int i){
  if (pdata[i] != nullptr)
  {
    delete[] pdata[i];
    size--;
  }
  else{
    std::cout<<"\nCAN'T FIND ELEMENT BY INDEX"<< i<<'\n';
    return 1;
  }
  
  return 0;
}

char* MyVector::operator[](int i){
  return pdata[i];
}

void MyVector::sort(){
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
        if (pdata[i] > pdata[j]) {
            std::swap(pdata[i], pdata[j]);
        }
    }
  }
}
