#include "headers/lib.h"


int main(){
    int ext = 0;
    int choice;

    while(ext == 0){
        printf("What do you wanna do?\n 1) Save 10 words\n 2) Print words\n 3) Count words in a file\n 4) Exit\n");
        scanf("%d", &choice);
        flushInput();       
        
        switch(choice){
            case 1:
                saveWords();
                break;
            case 2:
                printWords();
                break;
            case 3:
                countWords();
                break;
            case 4:
                ext++;
                break;
            default:
                printf("Wrong input");
                break;
        }
    }

    return 0;
}
