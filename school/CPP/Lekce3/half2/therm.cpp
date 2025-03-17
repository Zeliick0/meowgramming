#include "lib.h"
using namespace std;

Thermo::Thermo(float t) {
    temp = t;
}

float Thermo::CtoF(float t) {
    float fTemp;
    fTemp = (t * 1.8) + 32;

    return fTemp;
}

void Thermo::tempInfo() {
    cout << " Temp in Celsius is " << temp << endl
         << " Temp in Fahrenheit is " << CtoF(temp) << endl;
}
