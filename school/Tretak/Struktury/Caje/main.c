#include "headers/tealib.h"
#include <stdio.h>

int main(){
    TEA tearr[N];
    int count = 0;
    int ext = 0;
    int choice;
    int green = 0;
    while (ext == 0) {
    
    printf("What do you wanna do?\n 1) Add a tea\n 2) Show tea info\n 3) Amount of green teas\n 4) Sort by num\n 5) Sort by name\n 6) Sort by price\n 7) Save to file\n 8) Find by name\n 9) Remove by number\n 10) Save to bin\n 11) Print from bin\n 12) Exit\n");
    scanf("%d", &choice);
    flushInput();
        
    switch (choice) {
        case 1:
            tearr[count] = addTea(count);
            count++;
            break; 
        case 2:
            printInfo(tearr, count);
            break;
       case 3:
            printf("There are %d green teas! \n", greenteas(tearr, count));             
            break;
        case 4:
            sortNum(tearr, count);
            printInfo(tearr, count);
            break;
        case 5:
            sortABC(tearr, count);
            printInfo(tearr, count);
            break;
        case 6:
            sortPrice(tearr, count);
            printInfo(tearr, count);
            break;
        case 7:
            saveToTXT(tearr, count);
            break;
        case 8:
            findTea(tearr, count);
            break;
        case 9:
            removeByNum(tearr, &count);
            break;
        case 10:
            savetoBin(tearr, count);
            break;
        case 11:
            printBin("dat.bin");
            break;
        case 12:
            ext = 1;
            break;
        default:
            printf("Wrong input");
            break;
    }



    
    }
    return 0;
}
