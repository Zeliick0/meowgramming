#include "lib.h"
using namespace std;
Zlomek::Zlomek() {}

Zlomek::Zlomek(int c, int j) {
    jmenovatel = j;
    citatel = c;
}
ostream& operator <<(ostream& output, const Zlomek &zlomek) {
    output << zlomek.citatel << "/" << zlomek.jmenovatel;
    return output;
}

istream& operator >>(istream& input, Zlomek &zlomek) {
    char lomitko;
    cout << endl << "Zadej citatel a jmenovatel:";
    cout << endl << "c/j: ";
    input >> zlomek.citatel >> lomitko >> zlomek.jmenovatel;
    return input;
}

Zlomek operator +(Zlomek &a, Zlomek &b) {
    Zlomek f;
    f.citatel = (a.citatel * b.jmenovatel) + (b.citatel * a.jmenovatel);
    f.jmenovatel = a.jmenovatel * b.jmenovatel;
    f.zakTvar();
    return f;
}

Zlomek operator -(Zlomek &a, Zlomek &b) {
    Zlomek f;
    f.citatel = (a.citatel * b.jmenovatel) - (b.citatel * a.jmenovatel);
    f.jmenovatel = a.jmenovatel * b.jmenovatel;
    f.zakTvar();
    return f;
}

Zlomek operator *(Zlomek &a, Zlomek &b) {
    Zlomek f;
    f.citatel = a.citatel * b.citatel;
    f.jmenovatel = a.jmenovatel * b.jmenovatel;
    f.zakTvar();
    return f;
}

Zlomek operator /(Zlomek &a, Zlomek &b) {
    Zlomek f;
    f.citatel = a.citatel * b.jmenovatel;
    f.jmenovatel = a.jmenovatel * b.citatel;
    f.zakTvar();
    return f;
}
