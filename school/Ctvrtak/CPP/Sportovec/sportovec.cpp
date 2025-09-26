#include "lib.h"
using namespace std;

Sportovec::Sportovec() {}

Sportovec::Sportovec(string n, int a) {
    this->name = n;
    this->age = a;
}

void Sportovec::setAge() {
    int age;
    cout << "Zadej vek: " << endl;
    cin >> age;
}

ostream &operator <<(ostream &output, const Sportovec &sportovec) {
    output << "Jmeno: " << sportovec.name << endl
           << "Prijmeni: " << sportovec.surname << endl
           << "Vek: " << sportovec.age << endl;

    return output;
}

istream &operator >>(istream &input, Sportovec &sportovec) {
    cout << endl << "Zadej jmeno sportovce: ";
    input >> sportovec.name;
    
    cout << endl << "Zadej prijmeni sportovce: ";
    input >> sportovec.surname;

    cout << endl << "Zadej vek sportovce: ";
    input >> sportovec.age;
    
    sportovec.surname = sportovec.lexerChecker(sportovec.surname);
    sportovec.name = sportovec.lexerChecker(sportovec.name);

    return input;
}

string Sportovec::lexerChecker(string str) {
    if(str[0] >= 0x61 && str[0] <= 0x7A) {
        str[0] = str[0] - 0x20;
   }

    for (int i = 1; i < str.length(); i++) {
        if (str[i] >= 0x41 && str[i] <= 0x5A) {
            str[i] = str[i] + 0x20;
        }
    }

    return str;
}

void Sportovec::writeToFile(string path) {
    FILE * f;
    f = fopen(path.c_str(),"w");

    if (f == NULL){
        cout << "Soubor se nepovedlo otevrit";
        return;
    }
    
    string c = this->name + "," + this->surname + "\n";
    fputs(c.c_str(), f);

    fclose(f);
}

void Sportovec::readFile(string path) {
    FILE *f;
    f = fopen(path.c_str(), "r");

    if (f == NULL) {
        cout << "Soubor se nepovedlo otevrit";
        return;
    }
    
    char line[256];

    while (fgets(line, 256, f) != NULL) {
        char *token;
        char *n, *s;

        token = strtok(line, ",");
        strcpy(n, token);
        token = strtok(NULL, "\n");
        strcpy(s, token);
    }

    fclose(f);
}
