#include "lib.h"
#include <string>
using namespace std;

Person::Person() {}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

void Person::setName(){
    string iName;
    cout << "Input name: " << endl;
    cin >> iName;
  
    this->name = iName;
}

void Person::setAge() {
    int iAge;
    cout << "Input age: " << endl;
    cin >> iAge;

    this->age = iAge;
}

void Person::ageIncrement() {
    this->age = age + 1;
}

void Person::printName() {
    cout << "The persons name is: " << name << endl;
}

void Person::printAge() {
    cout << name << "'s age is " << age << endl;
}
