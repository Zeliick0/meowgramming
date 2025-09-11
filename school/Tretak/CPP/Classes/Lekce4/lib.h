#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person();
        Person(string n, int a);
        void setName();
        void setAge();
        void ageIncrement();
        void printName();
        void printAge();
};

#endif
