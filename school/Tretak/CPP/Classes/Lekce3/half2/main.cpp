#include "lib.h"
using namespace std;

int main() {
    Student st1("Gdam", "Aurecky", 18, 3.5);

    st1.studentInfo();
    st1.changeAvg();

    Thermo t1(23.5);
    t1.tempInfo();

    Book b1("Metamorphosis", "Franz Kafka", 200);
    Book b2("Harry Potter", "J. K. Rowling", 500);
    b1.bookInfo();
    if (b2.isLong() == true) {
        cout << "The book " << b2.getBookName() << " is longer than 300 pages" << endl; 
    }
    return 0;
}
