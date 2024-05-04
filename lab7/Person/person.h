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
  static bool autoAdd;
  static Person **persons;
  static size_t size;
  static size_t capacity;

  static void Print();

  Person(unsigned a, char *na, bool ge);
  virtual ~Person()
  {
    delete[] name;
  }
  virtual void show() = 0;
  void add();
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

  Worker(const Worker &per);
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
