#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
    private:
        string name;
        string surname;
        int age;
        float avgGrade;

    public:
        Student();
        Student(string n, string s, int a, float aG);
        void changeAvg();
        void studentInfo();
};

class Thermo {
    private:
        float temp;
    public:
        Thermo();
        Thermo(float t);
        void setTemp();
        float CtoF(float t);
        void tempInfo();

};

class Book {
    private:
        string bookName;
        string author;
        int pages;
    public:
        Book();
        Book(string bN, string a, int p);
        void bookInfo();
        bool isLong();
        string getBookName();
};

#endif
