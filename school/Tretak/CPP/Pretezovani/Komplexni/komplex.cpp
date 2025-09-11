#include "lib.h"
#include <cmath>
using namespace std;

ComplexNumbers::ComplexNumbers() {}

ComplexNumbers::ComplexNumbers(float x, float y) {
    real = x;
    img = y;
}

ostream& operator <<(ostream& output, const ComplexNumbers& complexNum) {
    if(complexNum.img < 0){
        output << complexNum.real << " " << complexNum.img << "i";
    } else {
        output << complexNum.real << " + " << complexNum.img << "i" << endl;
    }
    return output;
}

istream& operator >>(istream& input, ComplexNumbers& complexNum) {
    char whitespace;
    cout << endl << "Zadej realne a imaginarni cislo:";
    cout << endl << "x y: ";
    input >> complexNum.real >> whitespace >> complexNum.img;
    return input;
}

ComplexNumbers operator +(ComplexNumbers& x, ComplexNumbers& y) {
    ComplexNumbers f;
    f.real = x.real + y.real;
    f.img = x.img + y.img;
    return f;
}

ComplexNumbers operator -(ComplexNumbers& x, ComplexNumbers& y) {
    ComplexNumbers f;
    f.real = x.real - y.real;
    f.img  = x.img - y.img;
    return f;
}

ComplexNumbers operator *(ComplexNumbers& x, ComplexNumbers& y) {
    ComplexNumbers f;
    f.real = (x.real * y.real) - (x.img * y.img);
    f.img = (x.real * y.img) + (x.img * y.real);
    return f;
}

float operator !(ComplexNumbers& x) {
    return sqrt((x.real * x.real) + (x.img * x.img));
}

ComplexNumbers operator /(ComplexNumbers& x, ComplexNumbers& y) {
     
}
