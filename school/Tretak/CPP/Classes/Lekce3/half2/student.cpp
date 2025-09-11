#include "lib.h"
using namespace std;

Student::Student(string n, string s, int a, float aG) {
    name = n;
    surname = s;
    age = a;
    avgGrade = aG;
}

void Student::changeAvg() {
    float newGrade;
    cout << "Input the new average grade" << endl;
    cin >> newGrade;
    cin.ignore();

    this->avgGrade = newGrade;
}

void Student::studentInfo() {
    cout << "The students name is: " << name + " " + surname << endl
         << "The students age is: " << age << endl
         << "The students average grade is " << avgGrade << endl;
}
