#include "lib.h"
using namespace std;

int main() {
    string name;
    string surname;
    int choice;

    int ed = 1;
    while (ed == 1) {
        cout << "1) Jmeno a prijmeni" << endl 
             << "2) String to int" << endl 
             << "0) Exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                userInput(name, surname);
                nameLengths(name, surname);
                break;
            case 2: 
                stringNums();
                break;
            case 0:
                cout << "Oki bye" << endl;
                ed = 2;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }

    return 0;
}
