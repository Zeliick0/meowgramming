#include "lib.h"
using namespace std;

Osoby::Osoby(string n, int a) {
    age = a;
    name = n;
}

void Osoby::starnuti() {
    age = age + 1;
}
void Osoby::vypisOsobu() {
    cout << "Jmeno osoby je " << name << ", vek osoby je " << age << "." << endl;
}
