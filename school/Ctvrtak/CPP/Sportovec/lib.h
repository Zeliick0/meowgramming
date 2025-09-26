#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

class Sportovec {
        private:
            string name;
            string surname;
            int age;
        public:
            Sportovec();
            Sportovec(string n, int a);
            void setName();
            void setAge();
            void getName();
            void getAge();
            friend ostream &operator <<(ostream &output, const Sportovec &sportovec);
            friend istream &operator >>(istream &input, Sportovec &sportovec);
            string lexerChecker(string str);
            void writeToFile(string path);
            void readFile(string path);
};

#endif
