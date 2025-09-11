#include "lib.h"

//Clears out the scanf(stdin) buffer so no unwanted behaviour happens
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Converts inputed words for further comparation
void to_lowercase(char *string) {
    while (*string) {
        if (*string >= 'A' && *string <= 'Z') {
            *string = *string + ('a' - 'A');
        }
        string++;
    }
}

//Loads the file the user wants to work with
// !!Important since other functions won't work until the file is loaded into the arrays!!
// !!The file you input has to be in the correct format for parsing to work!!
int loadDictionary(const char* filename, char czech[][N], char english[][N], int lessons[], int maxWords) {
    FILE *f = fopen(filename, "r");
    if (!f) return 0;

    int count = 0;
    while (fscanf(f, "%[^;];%[^;];%d;\n", czech[count], english[count], &lessons[count]) == 3) {
        count++;
        if (count >= maxWords) break;
    }
    fclose(f);
    return count;
}

//Translates the word, checks both languages so the user can input either a czech or english word
void Translate(char czech[][N], char english[][N], int count) {
    char word[N];
    printf("Input a word (either Czech or English): \n");
    fgets(word, N, stdin);
    word[strcspn(word, "\n")] = '\0';
    to_lowercase(word);

    for (int i = 0; i < count; i++) {
        if (strcmp(czech[i], word) == 0) {
            printf("Translation: %s\n", english[i]);
            return;
        } else if (strcmp(english[i], word) == 0) {
            printf("Translation: %s\n", czech[i]);
            return;
        }
    }
    printf("Word not found.\n");
}

//Tests the user from a lesson of their choice
// Prints out results at the end of the test
void lesson_test(char czech[][N], char english[][N], int lessons[], int count) {
    int lesson, total = 0, correct = 0;
    char answer[N];

    printf("Which lesson do you want to test from?\n");
    scanf("%d", &lesson);
    flushInput();

    for (int i = 0; i < count; i++) {
        if (lessons[i] == lesson) {
            printf("What's the word \"%s\": ", czech[i]);
            fgets(answer, N, stdin);
            answer[strcspn(answer, "\n")] = '\0';
            to_lowercase(answer);

            if (strcmp(answer, english[i]) == 0) {
                printf("Correct!\n");
                correct++;
            } else {
                printf("Incorrect, the correct is \"%s\"\n", english[i]);
            }
            total++;
        }
    }
    if (total > 0) {
        printf("Results: %d correct out of %d. Success rate: %.2f%%\n", correct, total, (correct / (float)total) * 100);
    } else {
        printf("No words found in this lesson.\n");
    }
}

//Counts words in a lesson, user can input "*" for all words instead of a single lesson
int wordsInLesson(char czech[][N], int lessons[], int count) {
    char lesson[10];
    int word_count = 0;

    printf("Which lesson do you want to count words in (type * for all): ");
    scanf("%9s", lesson);
    flushInput();

    if (strcmp(lesson, "*") == 0) {
        return count;
    } else {
        int lesson_num = atoi(lesson);
        for (int i = 0; i < count; i++) {
            if (lessons[i] == lesson_num) {
                word_count++;
            }
        }
        return word_count;
    }
}

//Function appends a user-input word to the existing arrays and then rewrites the file to update it
void addWord(const char *filename, int *count, char czech[][N], char english[][N], int lessons[], int maxWords) {
    if (*count >= maxWords) {
        printf("Dictionary is full.\n");
        return;
    }

    printf("Enter a Czech word: ");
    fgets(czech[*count], N, stdin);
    czech[*count][strcspn(czech[*count], "\n")] = '\0';
    to_lowercase(czech[*count]);

    printf("Enter the word in English: ");
    fgets(english[*count], N, stdin);
    english[*count][strcspn(english[*count], "\n")] = '\0';
    to_lowercase(english[*count]);

    printf("Enter lesson number: ");
    scanf("%d", &lessons[*count]);
    flushInput();

    FILE *f = fopen(filename, "a");
    if (!f) {
        perror("Error opening file.");
        return;
    }
    fprintf(f, "%s;%s;%d;\n", czech[*count], english[*count], lessons[*count]);
    fclose(f);

    (*count)++;
    printf("Word successfully added.\n");
}

//Tests the user from random words across all lessons, keeps track of used words with a seperate array that checks if the index is "1" for used, "0" for not used, to not repeat a word
void randomTest(char czech[][N], char english[][N], int count) {
    int amount, correct = 0;
    char answer[N];
    int used[count];

    printf("How many words do you want to test (max %d): ", count);
    scanf("%d", &amount);
    flushInput();

    if (amount > count) {
        printf("Not enough words.\n");
        return;
    }

    memset(used, 0, sizeof(used));
    srand(time(NULL));

    for (int i = 0; i < amount; i++) {
        int idx;
        do {
            idx = rand() % count;
        } while (used[idx]);
        used[idx] = 1;

        printf("Translate the word \"%s\": ", czech[idx]);
        fgets(answer, N, stdin);
        answer[strcspn(answer, "\n")] = '\0';
        to_lowercase(answer);

        if (strcmp(answer, english[idx]) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect, the correct answer is \"%s\".\n", english[idx]);
        }
    }

    printf("\nQuiz complete! Correct answers: %d/%d (%.2f%%)\n", correct, amount, (float)correct / amount * 100);
}

//Either edits a word or deletes it
//The word has to be the czech part of the line the user wants to work with
//After selecting/rewriting the word it rewrites to file to update it
void EditWords(const char *filename, char czech[][N], char english[][N], int lessons[], int *count) {
    char choice, word[N];

    printf("Do you want to delete or edit? (d/e): ");
    scanf("%c", &choice);
    flushInput();

    if (choice == 'e') {
        printf("Enter the Czech word to edit: ");
        fgets(word, N, stdin);
        word[strcspn(word, "\n")] = '\0';
        to_lowercase(word);

        for (int i = 0; i < *count; i++) {
            if (strcmp(czech[i], word) == 0) {
                printf("Editing word \"%s\":\n", word);

                printf("Enter new Czech word: ");
                fgets(czech[i], N, stdin);
                czech[i][strcspn(czech[i], "\n")] = '\0';
                to_lowercase(czech[i]);

                printf("Enter new English word: ");
                fgets(english[i], N, stdin);
                english[i][strcspn(english[i], "\n")] = '\0';
                to_lowercase(english[i]);

                printf("Enter new lesson number: ");
                scanf("%d", &lessons[i]);
                flushInput();

                FILE *f = fopen(filename, "w");
                if (!f) {
                    perror("Error opening file.");
                    return;
                }
                for (int j = 0; j < *count; j++) {
                    fprintf(f, "%s;%s;%d;\n", czech[j], english[j], lessons[j]);
                }
                fclose(f);
                printf("Word updated successfully.\n");
                return;
            }
        }
        printf("Word not found.\n");
    } else if (choice == 'd') {
        printf("Enter the Czech word to delete: ");
        fgets(word, N, stdin);
        word[strcspn(word, "\n")] = '\0';
        to_lowercase(word);

        for (int i = 0; i < *count; i++) {
            if (strcmp(czech[i], word) == 0) {
                for (int j = i; j < *count - 1; j++) {
                    strcpy(czech[j], czech[j + 1]);
                    strcpy(english[j], english[j + 1]);
                    lessons[j] = lessons[j + 1];
                }
                (*count)--;

                FILE *f = fopen(filename, "w");
                if (!f) {
                    perror("Error opening file.");
                    return;
                }
                for (int j = 0; j < *count; j++) {
                    fprintf(f, "%s;%s;%d;\n", czech[j], english[j], lessons[j]);
                }
                fclose(f);
                printf("Word deleted successfully.\n");
                return;
            }
        }
        printf("Word not found.\n");
    } else {
        printf("Invalid choice.\n");
    }
}
