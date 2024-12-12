#include "lib.h"

int main() {
    int ext = 0;
    int choice;
    char filename[N];
    char czech[MAX_WORDS][N];
    char english[MAX_WORDS][N];
    int lessons[MAX_WORDS];
    int count = 0;

    printf("What file do you want to work with?\n");
    fgets(filename, N, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("\nDon't forget to load your dictionary!\n\n");

    while (ext == 0) {
        printf("What do you want to do?\n"
               "1) Load dictionary\n"
               "2) Translate a word\n"
               "3) Test from a lesson\n"
               "4) Count words\n"
               "5) Add a word\n"
               "6) Random test\n"
               "7) Edit or delete\n"
               "8) Exit\n");
        scanf("%d", &choice);
        flushInput();

        switch (choice) {
            case 1:
                count = loadDictionary(filename, czech, english, lessons, MAX_WORDS);
                printf("Loaded %d words.\n", count);
                break;
            case 2:
                Translate(czech, english, count);
                break;
            case 3:
                lesson_test(czech, english, lessons, count);
                break;
            case 4:
                printf("There are %d words.\n", wordsInLesson(czech, lessons, count));
                break;
            case 5:
                addWord(filename, &count, czech, english, lessons, MAX_WORDS);
                break;
            case 6:
                randomTest(czech, english, count);
                break;
            case 7:
                EditWords(filename, czech, english, lessons, &count);
                break;
            case 8:
                printf("Goodbye!\n");
                ext = 1;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
