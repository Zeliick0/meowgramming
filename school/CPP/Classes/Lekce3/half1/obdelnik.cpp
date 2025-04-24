#include "lib.h"
#include <cstdio>
using namespace std;

Obdelnik::Obdelnik(int h, int w) {
    height = h;
    width = w;
}

void Obdelnik::vypocitejObvod() {
    cout << "Obvod je " << (2 * width) + (2 * height) << endl;
}

void Obdelnik::vypocitejObsah() {
    cout << "Obsah je " << height * width << endl;
}

void Obdelnik::jeCtverec() {
    if(height == width) {
        cout << "Je ctverec" << endl;
    } else {
        cout << "Neni ctverec" << endl;
    }
}

void Obdelnik::zvetsit() {
    int mult = 1;
    cout << "Zadejte nasobic: " << endl;
    cin >> mult;
    cin.ignore();
    height = height * mult;
    width = width * mult;
}

void Obdelnik::infoObdelniku() {
    cout << "Vyska obdelniku je " << height << " , delka obdelniku je " << width << endl;
}
