#include "lib.h"
using namespace std;

Date::Date() {
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Date::Date(int d, int m, int y) {
    this->day = d;
    this->month = m;
    this->year = y;
}

void Date::setD(int x) {
    this->day = x;
}

void Date::setM(int x) {
    this->month = x;
}

void Date::setY(int x) {
    this->year = x;
}

int Date::getD() const {
    return this->day;
}

int Date::getM() const {
    return this->month;
}

int Date::getY() const {
    return this->year;
}

ostream &operator <<(ostream &output, const Date &date) {

}
