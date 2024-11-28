#include "headers/lib.h"

int main(){
    int ext = 0;
    int choice;
    char filename[N];
    Word dictionary[N];
    int count;
    int wordcount = 0;

    printf("What file do you want to work with?\n");
    fgets(filename,N,stdin);
    filename[strcspn(filename, "\n")] = '\0';

    while(ext == 0){
        printf("What do you wanna do?\n 1) Load dictionary\n 2) Translate a word\n 3) Test from a lesson\n 4) Count words\n 5) Add a word\n 6) Random test\n 7) Edit or delete\n 8) Exit\n");
        scanf("%d", &choice);
        flushInput();

        switch (choice) {
            case 1:
              count = loadDictionary(filename,dictionary);
              printf("Loaded %d words\n", count);
                break;
            case 2:
                Translate(dictionary, count);
                break;
            case 3:
                lesson_test(dictionary,count);
                break;
            case 4:
                wordcount = wordsInLesson(dictionary,count);
                printf("There are %d words.\n", wordcount);
                break;
            case 5:
                addWord(filename,count,dictionary);
                count = loadDictionary(filename, dictionary);
                break;
            case 6:
                randomTest(dictionary,count);
                break;
            case 7:
                EditWords(filename,dictionary,count);
                count = loadDictionary(filename, dictionary);
                break;
            case 8:
                printf("Okie bye\n");
                ext++;
                break;
            default:
                printf("Wrong input\n");
                break;
        }
    }

    return 0;
}
