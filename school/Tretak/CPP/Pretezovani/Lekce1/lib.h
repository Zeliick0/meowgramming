#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <iomanip>
using namespace std;

class Zlomek {
    private:
        int citatel;
        int jmenovatel;

        int gcd(int a, int b) const {
            return b == 0 ? a : gcd(b, a % b);
        }

        void zakTvar() {
            int d = gcd(abs(citatel), abs(jmenovatel));
            citatel /= d;
            jmenovatel /= d;

            if (jmenovatel < 0) {
                citatel = -citatel;
                jmenovatel = -jmenovatel;
            }
        }
    public:
        Zlomek();
        Zlomek(int c, int j);
        void Zinput();
        void Zoutput();
        void Zmult();
        void Zsum();
        void Zsub();
        void Zdiv();
        friend ostream& operator <<(ostream& output, const Zlomek& zlomek);
        friend istream& operator >>(istream& input, Zlomek& zlomek);
        friend Zlomek operator +(Zlomek& a, Zlomek& b);
        friend Zlomek operator -(Zlomek& a, Zlomek& b);
        friend Zlomek operator *(Zlomek& a, Zlomek& b);
        friend Zlomek operator /(Zlomek& a, Zlomek& b);
};

#endif
