#include "lib.h"
using namespace std;

Book::Book(string bN, string a, int p) {
    bookName = bN;
    author = a;
    pages = p;
}

void Book::bookInfo() {
    cout << "Book name is: " << bookName << endl
         << "The author is:  " << author << endl
         << "It has " << pages << " pages" << endl;
}

bool Book::isLong() {
    if (pages > 300) {
        return true;
    } else return false;
}

string Book::getBookName() {
    return this->bookName;
}
