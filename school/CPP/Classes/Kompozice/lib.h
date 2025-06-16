#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Client {
    private:
        int id;
        string name;
        string surname;
    public:
        Client();
        Client(int i, string n, string s);
        void setId(int x);
        int getId() const;
        void setName(string x);
        string getName() const;
        void setSurname(string x);
        string getSurname() const;
        friend istream &operator >>(istream &input, Client &client);
        friend ostream &operator <<(ostream &output, const Client &client);
};

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int d, int m, int y);
        void setD(int x);
        int getD() const;
        void setM(int x);
        int getM() const;
        void setY(int x);
        int getY() const;
        friend istream &operator >>(istream &input, Date &date);
        friend ostream &operator <<(ostream &output, const Date &date);
        
};

#endif
