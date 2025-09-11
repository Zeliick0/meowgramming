#include "headers/lib.h"
#include <stdio.h>
#include <string.h>

void flushInput(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void saveWords(){
    char slovicka[N];
    char filename[N];
    printf("Insert the name of your file:\n");
    fgets(filename,N,stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Input a string (max length is 255): \n");
    fgets(slovicka,N, stdin);
    slovicka[strcspn(slovicka, "\n")] = '\0';

    FILE *f = fopen(filename, "w");
    if(f == NULL){
        perror("There was an error while opening the file oopsie.");
    }

    fprintf(f, "%s", slovicka);
    fclose(f);
}

void printWords(){
    int i = 0;
    char filename[N];
    char slovicka[N];
    char *token;
    char *rest;
    printf("Insert the name of your file:\n");
    fgets(filename,N,stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    FILE *f = fopen(filename, "r");

    if (f == NULL){
        perror("There was an error opening the file");
    }

    fgets(slovicka, N, f);
    rest = slovicka;

    while((token = strtok_r(rest, " ", &rest))){
        printf("Word %d is %s\n",i +1,token);
        i++;
    }
}

void countWords(){
    int i = 0;
    char filename[N];
    char slovicka[N];
    char *token;
    char *rest;
    printf("Insert the name of your file:\n");
    fgets(filename,N,stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    FILE *f = fopen(filename, "r");

    if (f == NULL){
        perror("There was an error opening the file");
    }

    fgets(slovicka, N, f);
    slovicka[strcspn(slovicka, "\n")] = '\0';
    rest = slovicka;

    while((token = strtok_r(rest, " ", &rest))){
        i++;
    }
    printf("There are %d words!\n", i);
}
