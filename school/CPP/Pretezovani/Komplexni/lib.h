#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <iomanip>
using namespace std;

class ComplexNumbers {
    private:
        float real, img;
    public:
        ComplexNumbers();
        ComplexNumbers(float x, float y);
        friend ostream& operator <<(ostream& output, const ComplexNumbers& complexNum);
        friend istream& operator >>(istream& input, ComplexNumbers& complexNum);
        friend ComplexNumbers operator +(ComplexNumbers& x, ComplexNumbers& y);
        friend ComplexNumbers operator -(ComplexNumbers& x, ComplexNumbers& y);
        friend ComplexNumbers operator *(ComplexNumbers& x, ComplexNumbers& y);
        friend float operator !(ComplexNumbers& x);
        friend ComplexNumbers operator /(ComplexNumbers& x, ComplexNumbers& y);

};
#endif
