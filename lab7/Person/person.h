#pragma once

#include <cstring>
#include <iostream>

class Person
{
protected:
  unsigned age;
  char *name;
  bool gender;

public:
  static Person **persons;
  static size_t size;
  static size_t capacity;

  Person(unsigned a, char *na, bool ge);
  virtual ~Person()
  {
    delete[] name;
  }
  virtual void show() = 0;
  virtual void add() = 0;
  Person &operator=(const Person &per);
  Person(const Person &per);
};

class Employee : public Person
{
protected:
  char *workplace;

public:
  Employee(unsigned a, char *na, bool ge, char *workp);

  void show();

  void add();

  ~Employee();

  Employee &operator=(const Employee &per);
  Employee(const Employee &per);
};

class Worker : public Employee
{
protected:
  unsigned salary;

public:
  Worker(unsigned a, char *na, bool ge, char *workp, unsigned sal);

  void show();

  Worker &operator=(const Worker &per);
  //Worker(const Worker &per);
  //верный конструктор копирования для воркера сам генерится компилятором что я продемонстрировал в main.cpp(тут нет динамического выделения памяти как в других классах)
};

class Engineer : public Worker
{
protected:
  char *specialization;

public:
  Engineer(unsigned a, char *na, bool ge, char *workp, unsigned sal, char *spec);

  void show();

  ~Engineer();

  Engineer &operator=(const Engineer &per);
  Engineer(const Engineer &per);
};
