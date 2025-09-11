#include "lib.h"
using namespace std;

Client::Client() {
    this->id = 0;
    this->name = "";
    this->surname = "";
}

Client::Client(int i, string n, string s) {
    this->id = i;
    this->name = n;
    this->surname = s;
}

void Client::setId(int x) {
    this->id = x;
}

void Client::setName(string x) {
    this->name = x;
}

void Client::setSurname(string x) {
    this->surname = x;
}

int Client::getId() const {
    return this->id;
}

string Client::getName() const {
    return this->name;
}

string Client::getSurname() const {
    return this->surname;
}

ostream &operator <<(ostream &output, const Client &client) {
    output << "ID: " << client.id << endl
           << "Name: " << client.name << endl
           << "Surname: " << client.surname << endl;

    return output;
}

istream &operator >>(istream &input, Client &client) {
    cout << endl << "Enter ID NAME SURNAME: " << endl;
    input >> client.id >> client.name >> client.surname;
    return input;
}


