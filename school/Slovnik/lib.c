#include "headers/lib.h"


void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int loadDictionary(const char* filename, Word dictionary[]) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;
    int count = 0;
    while (fscanf(file, "%[^;];%[^;];%d;\n", dictionary[count].czech, dictionary[count].english, &dictionary[count].lecture) == 3) {
        count++;
    }
    fclose(file);
    return count;
}

void Translate(Word dictionary[], int count) {
    char word[N];

    printf("Input a word (either cz or en): \n");
    fgets(word,N,stdin);
    word[strcspn(word, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcasecmp(dictionary[i].czech, word) == 0) {
            printf("Translation: %s\n", dictionary[i].english);
            return;
        } else if (strcasecmp(dictionary[i].english, word) == 0) {
            printf("Translation: %s\n", dictionary[i].czech);
            return;
        }
    }
    printf("Word not found.\n");
}

