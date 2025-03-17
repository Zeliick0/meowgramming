#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <iomanip>
using namespace std;

class Osoby {
    private:
        int age;
        string name;
    public:
        Osoby(string n, int a);
        void starnuti();
        void vypisOsobu();
};

class Obdelnik {
    private:
        int height;
        int width;
    public:
        Obdelnik(int h, int w);
        void vypocitejObvod();
        void vypocitejObsah();
        void zvetsit();
        void jeCtverec();
        void infoObdelniku();
};

#endif
