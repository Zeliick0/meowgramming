#include "lib.h"
using namespace std;

int main() {
    string name;
    string surname;
    cout << "Zadejte jmeno: ";
    cin >> name;
    
    cout << "Zadejte prijmeni: ";
    cin >> surname;

    string fullName = name + " " + surname;
    cout << "Cele jmeno je " << fullName << endl;
    cout << "Jmeno je dlouhe " << name.length() << " znaku" << endl;
    cout << "Prijmeni je dlouhe " << surname.length() << " znaku" << endl;
    return 0;
}
