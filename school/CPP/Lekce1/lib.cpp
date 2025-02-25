#include "headers/lib.h"
using namespace std;

void addition() {
    int x,y;

    cout << "Zadej prvni cislo : ";
    cin >> x;

    cout << "Zadej druhe cislo: ";
    cin >> y;

    cout << "Soucet cisel je " << x + y << endl;

}

void decSubstraction() {
    float x;
    float y;

    cout << "Zadejte prvni desetinne cislo: ";
    cin >> x;
    
    cout << "Zadejte druhe desetinne cislO: ";
    cin >> y;

    cout << "Rozdil cisel je: " << x - y << endl;
}

void power() {
    int x;

    cout << "Zadejte cislo: ";
    cin >> x;

    cout << "Dvojnasobek: " << x * 2 << endl;
    cout << "Druha mocnina: " << x * x << endl;
}

void circleCirc() {
    int r;

    cout << "Zadejte polomer kruhu: ";
    cin >> r;

    cout << "Obvod kruhu je: " << 2 * M_PI * r << endl;
}

void mToCm() {
    float x;
    const int prevod = 100;

    cout << "Zadejte pocet metru: ";
    cin >> x;

    cout << "Je to " << x * prevod << " centimetru" << endl;
}
