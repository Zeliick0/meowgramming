#include "headers/lib.h"


int main(){
    char slovicka[N];
    int ext = 0;
    int choice;

    while(ext == 0){
        printf("What do you wanna do?\n 1) Save 10 words\n 2) Print words\n 3) Exit\n");
        scanf("%d", &choice);
        flushInput();       
        
        switch(choice){
            case 1:
                saveWords(slovicka);
                break;
            case 2:
                break;
            case 3:
                ext++;
                break;
            default:
                printf("Wrong input");
                break;
        }
    }

    return 0;
}
