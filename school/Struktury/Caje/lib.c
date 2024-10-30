#include "headers/tealib.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void flushInput(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

TEA addTea(int count){
    TEA tea;

    tea.Number = count;

    printf("What's the name of your tea? ");
    fgets(tea.Name, N, stdin);
    tea.Name[strcspn(tea.Name, "\n")] = '\0';

    printf("What's type of tea is it? ");
    fgets(tea.Type, N, stdin);
    tea.Type[strcspn(tea.Type, "\n")] = '\0';

    printf("What's the price of the tea? ");
    scanf("%f", &tea.Price);
    flushInput();

    return tea;
}

void printInfo(TEA tearr[], int count){
    for (int i = 0;i<count;i++) {
        printf("| Number: %d | Name: %s | Type: %s | Price: %.2f |\n", tearr[i].Number, tearr[i].Name, tearr[i].Type, tearr[i].Price);
    }
}

int greenteas(TEA tearr[], int count){
    int green = 0;
    for (int i = 0;i<count;i++) {
        if(strcasecmp(tearr[i].Type, "green") == 0){
            green++;
        }
    }

    return green;
}

int compareNum(const void *a, const void *b){
    TEA *teaA = (TEA *)a;
    TEA *teaB = (TEA *)b;

    return teaA->Number - teaB->Number;
}

int compareABC(const void *a, const void *b){
    TEA *teaA = (TEA *)a;
    TEA *teaB = (TEA *)b;

    return strcasecmp(teaA->Name, teaB->Name);
}

int comparePrice(const void *a, const void *b){
    TEA *teaA = (TEA *)a;
    TEA *teaB = (TEA *)b;

    if (teaA->Price > teaB->Price) return -1;
    if (teaA->Price < teaB->Price) return 1;
    return 0;
}


void sortNum(TEA tearr[], int count){
   qsort(tearr, count, sizeof(TEA), compareNum);
}

void sortABC(TEA tearr[], int count){
  qsort(tearr, count, sizeof(TEA), compareABC);
}

void sortPrice(TEA tearr[], int count){
    qsort(tearr, count, sizeof(TEA), comparePrice);
}

void saveToTXT(TEA tearr[], int count){
    FILE *f;
    if ((f = fopen("teas.txt", "w")) == NULL) {
        perror("Couldn't open the file.");
    }
    
     for (int i = 0;i<count;i++) {
        fprintf(f, "| Number: %d | Name: %s | Type: %s | Price: %.2f |\n", tearr[i].Number, tearr[i].Name, tearr[i].Type, tearr[i].Price);
    }
    fclose(f);
}

void findTea(TEA tearr[], int count){
    char type[N];
    printf("What type of tea do you want? ");
    fgets(type, N, stdin);
    type[strcspn(type, "\n")] = '\0';

    for(int i = 0;i<count;i++) {
        if (strcasecmp(tearr[i].Type, type) == 0){
         printf("| Number: %d | Name: %s | Type: %s | Price: %.2f |\n", tearr[i].Number, tearr[i].Name, tearr[i].Type, tearr[i].Price);   
        }
    }
}

int removeByNum(TEA tearr[], int *count){
    int index = -1;
    int num;

    printf("Which tea do you want to remove? ");
    scanf("%d", &num);
    flushInput();

    for (int i = 0;i< *count;i++) {
        if (tearr[i].Number == num) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("The tea with this number wasn't found..\n");
    }
    
    for (int i = index;i< *count - 1;i++) {
        tearr[i] = tearr[i +1];
    }
    
    (*count)--;
    return 1;
}

void savetoBin(TEA tearr[], int count){
    sortABC(tearr, count);
    
    FILE *data;

    if((data = fopen("dat.bin", "wb")) == NULL ){
        perror("Couldn't open file.");
    }

    fwrite(tearr, sizeof(TEA), count, data);
    fclose(data);
}

void printBin(const char *filename){
    TEA teaArray[N];
    FILE *data;
    
    if((data = fopen(filename, "rb")) == NULL ){
        perror("Couldn't open file.");
    }
    
    size_t readElements = fread(teaArray, sizeof(TEA), N, data);

    fclose(data);

    printf("Tea information: \n");
    printInfo(teaArray, readElements);
}
