# include "headers/lib.h"


int main(){
    int ext = 0;
    int choice;
    char filename[N];
    Word dictionary[N];
    int count;


    printf("What file do you want to work with?\n");
    fgets(filename,N,stdin);
    filename[strcspn(filename, "\n")] = '\0';

    while(ext == 0){
        printf("What do you wanna do?\n 1) Load dictionary\n 2) Translate a word\n");
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
            default:
                break;
        }
    }

    return 0;
}
