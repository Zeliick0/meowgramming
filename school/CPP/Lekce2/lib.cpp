#include "lib.h"
#include <string>
using namespace std;

void userInput(string &name, string &surname) {
 cout << "Input name: ";
 getline(cin, name);

 cout << "Input surname: ";
 getline(cin, surname);
 cout << "Full name is: " << name + " " + surname << endl;
}

void nameLengths(const string &name, const string &surname) {
    cout << "The name is " << name.length() << " letters long." << endl;
    cout << "The surname is " << surname.length() << " letters long." << endl;
} 

void stringNums() {
    string meow;
    int num;

    cout << "Input a word" << endl;
    getline(cin, meow);

   int meowNum = stoi(meow);
   cout << meowNum;
}
