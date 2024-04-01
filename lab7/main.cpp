#include "person.h"

Person **Person::persons = new Person*[2];

size_t Person::size = 0;

size_t Person::capacity = 2;


int main() {
  Employee emp(1337, "cheliks", 1, "bmstu");
  Worker wrk(18, "vanek", 0, "zavod", 15);
  Engineer eng(12, "vlados", 1, "mai", 15000, "space engineer");
  Engineer eng1(123, "slavik", 1, "fabrica", 15000, "airplane specialization");
  emp.add();
  wrk.add();
  eng.add();
  eng1.add();
  for (size_t i = 0; i < Person::size; i++) {
    Person::persons[i]->show();
  }
  delete[] Person::persons;
  return 0;
}
