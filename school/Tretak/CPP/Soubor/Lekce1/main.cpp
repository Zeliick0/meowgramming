#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int value;
    fstream file;
    
    file.open("meow.txt", ios::in);

    if(file.fail()) {
        perror("Error while opening the file..");
        return -1;
    }else {
        cout << ">~<" << endl;
    }
    
    file >> value;
    cout << "File data: " << value << endl;
    

    file.close();
    return 0;
}
