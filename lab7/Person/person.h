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

  Person(unsigned a = 0, char *na = "\0", bool ge = 0) : age(a), gender(ge)
  {
    name = new char[strlen(na) + 1];
    strcpy(name, na);
  }
  virtual ~Person()
  {
    delete[] name;
  }
  virtual void show() = 0;
  virtual void add() = 0;

};

class Employee : public Person
{
protected:
  char *workplace;

public:
  Employee(unsigned a = 0, char *na = "\0", bool ge = 0, char *workp = "\0") : Person(a, na, ge)
  {
    workplace = new char[strlen(workp) + 1];
    strcpy(workplace, workp);
  }

  void show() {
    std::cout << "employee " << age << ' ' << name << ' ' << gender << ' ' << workplace << '\n';
  }

  void add() {
    if (size >= capacity) {
      capacity *= 2;
      Person **tmp = new Person*[capacity];
      for (size_t i = 0; i < size; i++) {
        tmp[i] = persons[i];
      }
      delete[] persons;
      persons = tmp;
    }
    persons[size++] = this;
  }

  ~Employee() {
    delete[] workplace;
  }
};

class Worker : public Employee
{
protected:
  unsigned salary;
public:
  Worker(unsigned a = 0, char *na = "\0", bool ge = 0, char *workp = "\0", unsigned sal = 0) : Employee(a, na, age, workp) {
    salary = sal;
  }

  void show() {
    std::cout << "worker " << age << ' ' << name << ' ' << gender << ' ' << workplace << ' ' << salary << '\n';
  }

};

class Engineer : public Worker
{
protected:
  char* specialization;
public:
  Engineer(unsigned a = 0, char *na = "\0", bool ge = 0, char *workp = "\0", unsigned sal = 0, char* spec = "\0") : Worker(a, na, ge, workp, sal) {
    specialization = new char[strlen(spec) + 1];
    strcpy(specialization, spec);
  }

void show() {
    std::cout << "engineer " << age << ' ' << name << ' ' << gender << ' ' << workplace << ' ' << salary << ' ' << specialization << '\n';
  }

  ~Engineer() {
    delete[] specialization;
  }
};
