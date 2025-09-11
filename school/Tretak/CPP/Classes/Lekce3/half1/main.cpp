#include "lib.h"
#include <iostream>
using namespace std;


int main () {
    int end = 0;
    int choice;
    Osoby o1("Jakub", 17);
    Obdelnik ob1(10, 7);

    while (end == 0) {
        cout << "1)Vypis osoby" << endl
             << "2)Starnuti" << endl
             << "3)Obvod a obsah obdelniku" << endl
             << "4)Je obdelnik ctverec?" << endl
             << "5)Zvets obdelnik" << endl
             << "6)Info obdelniku" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                o1.vypisOsobu();
                break;
            case 2:
                o1.starnuti();
                break;
            case 3:
                ob1.vypocitejObvod();
                ob1.vypocitejObsah();
                break;
            case 4:
                ob1.jeCtverec();
                break;
            case 5:
                ob1.zvetsit();
                break;
            case 6:
                ob1.infoObdelniku();
                break;
            case 10:
                end = 1;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }
}
