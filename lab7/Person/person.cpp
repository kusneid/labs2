#include "person.h"

void Person::Print(){
  for (size_t i = 0; i < Person::size; i++) {
    Person::persons[i]->show();
  }
}

Person::Person(unsigned a = 0, char *na = "\0", bool ge = 0) : age(a), gender(ge)
{
  name = new char[strlen(na) + 1];
  strcpy(name, na);
  if (autoAdd)
  {
    add();
  }
}

Person &Person::operator=(const Person &per)
{
  age = per.age;
  if (name)
  {
    delete[] name;
  }
  name = new char[strlen(per.name) + 1];
  strcpy(name, per.name);
  gender = per.gender;
  return *this;
}

Person::Person(const Person &per)
{
  age = per.age;
  name = new char[strlen(per.name) + 1];
  strcpy(name, per.name);
  gender = per.gender;
  
  
}

Employee::Employee(unsigned a, char *na = "\0", bool ge = 0, char *workp = "\0") : Person(a, na, ge)
{
  workplace = new char[strlen(workp) + 1];
  strcpy(workplace, workp);
}

void Employee::show()
{
  std::cout << "employee " << age << ' ' << name << ' ' << gender << ' ' << workplace << '\n';
}

void Person::add()
{
  if (size >= capacity)
  {
    capacity *= 2;
    Person **tmp = new Person *[capacity];
    for (size_t i = 0; i < size; i++)
    {
      tmp[i] = persons[i];
    }
    delete[] persons;
    persons = tmp;
  }
  persons[size++] = this;
}

Employee::~Employee()
{
  delete[] workplace;
}

Employee &Employee::operator=(const Employee &per)
{
  age = per.age;
  if (name)
  {
    delete[] name;
  }
  name = new char[strlen(per.name) + 1];
  strcpy(name, per.name);
  gender = per.gender;
  if (workplace)
  {
    delete[] workplace;
  }
  workplace = new char[strlen(per.workplace) + 1];
  strcpy(workplace, per.workplace);
  return *this;
}

Employee::Employee(const Employee &per)
{
  age = per.age;
  name = new char[strlen(per.name) + 1];
  strcpy(name, per.name);
  gender = per.gender;
  workplace = new char[strlen(per.workplace) + 1];
  strcpy(workplace, per.workplace);
}

Worker::Worker(const Worker& per):Employee(per),salary(per.salary){}//тут11111111111!!!

Worker::Worker(unsigned a = 0, char *na = "\0", bool ge = 0, char *workp = "\0", unsigned sal = 0) : Employee(a, na, ge, workp)
{
  salary = sal;
}

void Worker::show()
{
  std::cout << "worker " << age << ' ' << name << ' ' << gender << ' ' << workplace << ' ' << salary << '\n';
}

Worker &Worker::operator=(const Worker &per)
{
  age = per.age;
  if (name)
  {
    delete[] name;
  }
  name = new char[strlen(per.name) + 1];
  strcpy(name, per.name);
  gender = per.gender;
  if (workplace)
  {
    delete[] workplace;
  }
  workplace = new char[strlen(per.workplace) + 1];
  strcpy(workplace, per.workplace);
  salary = per.salary;
  return *this;
}



Engineer::Engineer(unsigned a = 0, char *na = "\0", bool ge = 0, char *workp = "\0", unsigned sal = 0, char *spec = "\0") : Worker(a, na, ge, workp, sal)
{
  specialization = new char[strlen(spec) + 1];
  strcpy(specialization, spec);
}

void Engineer::show()
{
  std::cout << "engineer " << age << ' ' << name << ' ' << gender << ' ' << workplace << ' ' << salary << ' ' << specialization << '\n';
}

Engineer::~Engineer()
{
  delete[] specialization;
}

Engineer &Engineer::operator=(const Engineer &per)
{
  age = per.age;
  if (name)
  {
    delete[] name;
  }
  name = new char[strlen(per.name) + 1];
  strcpy(name, per.name);
  gender = per.gender;
  if (workplace)
  {
    delete[] workplace;
  }
  workplace = new char[strlen(per.workplace) + 1];
  strcpy(workplace, per.workplace);
  salary = per.salary;
  if (specialization)
  {
    delete[] specialization;
  }
  specialization = new char[strlen(per.specialization) + 1];
  strcpy(specialization, per.specialization);
  return *this;
}

Engineer::Engineer(const Engineer &per)
{
  age = per.age;
  name = new char[strlen(per.name) + 1];
  strcpy(name, per.name);
  gender = per.gender;
  workplace = new char[strlen(per.workplace) + 1];
  strcpy(workplace, per.workplace);
  salary = per.salary;
  specialization = new char[strlen(per.specialization) + 1];
  strcpy(specialization, per.specialization);
}
