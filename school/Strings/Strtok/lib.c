#include "headers/lib.h"
#include <stdio.h>

void flushInput(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void saveWords(char slovicka[]){
    char filename[N];
    char *vysl;
    char *rest = slovicka;
    printf("Insert the name of your file:\n");
    fgets(filename,N,stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Input a string of 10 words: \n");
    fgets(slovicka,N, stdin);
    slovicka[strcspn(slovicka, "\n")] = '\0';

    FILE *f = fopen(filename, "w");
    vysl = strtok_r(rest, ";", &rest);
    while((vysl = strtok_r(rest, " ", &rest)))
       fprintf(f, "%s\n", vysl);
    fclose(f);
}
