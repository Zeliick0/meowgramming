#include "headers/lib.h"
using namespace std;

int main() {
    int end = 0;
    int input = 0;
    while (end == 0) {
        cout << "Vyber operaci\n 1) Soucet cisel\n 2) Rozdil desetinnych\n 3) Dvojnasobek a mocnina\n 4) Obvod kruhu\n 5) Prevod metru na cm\n";
        cin >> input;

        switch (input) {
            case 1:
                addition();
                break;
            case 2: 
                decSubstraction();
                break;
            case 3:
                power();
                break;
            case 4:
                circleCirc();
                break;
            case 5:
                mToCm();
                break;
            case 6:
                end++;
                break;
            default:
                cout << "Spatny input";
                break;
        }
    }

     return 0;
}
