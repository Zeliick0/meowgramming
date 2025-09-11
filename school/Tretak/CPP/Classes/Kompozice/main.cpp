#include "lib.h"
using namespace std;

int main() {
    Client c1(1, "Jakub", "Hovadik");
    Client c2;

    cout << c1;
    cin >> c2;
    cout << c2;

    return 0;
}
