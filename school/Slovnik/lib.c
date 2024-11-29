#include "headers/lib.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Function for resetting scanf
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Function that converts the whole string to lowercase for handling user inputs correctly
void to_lowercase(char *string) {
    while (*string) {
        if (*string >= 'A' && *string <= 'Z') {
            *string = *string + ('a' - 'A');
        }
        string++;
    }
}

// Function that takes a correctly formatted text file and fills an array of structs with the values
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

//Function that takes user input and translates it
void Translate(Word dictionary[], int count) {
    char word[N];

    printf("Input a word (either cz or en): \n");
    fgets(word,N,stdin);
    word[strcspn(word, "\n")] = '\0';
    to_lowercase(word);

    for (int i = 0; i < count; i++) {
        if (strcmp(dictionary[i].czech, word) == 0) {
            printf("Translation: %s\n", dictionary[i].english);
            return;
        } else if (strcmp(dictionary[i].english, word) == 0) {
            printf("Translation: %s\n", dictionary[i].czech);
            return;
        }
    }
    printf("Word not found.\n");
}

//Function that takes a number as user input and tests the user from the according words
void lesson_test(Word dictionary[], int count){
    int total = 0, correct = 0;
    int lesson;   
    char answer[N];

    printf("Which lesson do you wanna take a test from?\n");
    scanf("%d", &lesson);
    flushInput();
    
    for (int i = 0; i < count; i++) {
        if (dictionary[i].lecture == lesson) {
        printf("What's the word \"%s\":  ", dictionary[i].czech);
        fgets(answer,N,stdin);
        answer[strcspn(answer, "\n")] = '\0';
        to_lowercase(answer);

        if(strcmp(answer, dictionary[i].english) == 0){
             printf("Correct\n");
             correct++;
        }else {
               printf("Incorrect, the correct is \"%s\"\n", dictionary[i].english); 
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

//Function that counts all words in a lesson which the user inputs
int wordsInLesson(Word dictionary[], int count){
    char lesson[10];
    int word_count = 0;

    printf("Which lesson do you wanna count the words in (type * for all)\n");
    scanf("%9s", lesson);
    flushInput();

    if(strcmp(lesson, "*") == 0) {
        return count;
    } else{
        int lesson_num = atoi(lesson);
        for(int i = 0; i < count; i++){
            if(dictionary[i].lecture == lesson_num){
                word_count++;
            }
        }
        return word_count;
    }
}

//Adds a word to the struct and then rewrites the file to add it to it as well
void addWord(const char* filename, int count, Word dictionary[]){
    char cz[N], en[N];
    int lesson;

    printf("Enter a Czech word: ");
    fgets(cz,N,stdin);
    cz[strcspn(cz, "\n")] = '\0';
    to_lowercase(cz);

    printf("Enter the word in English: ");
    fgets(en,N,stdin);
    en[strcspn(en, "\n")] = '\0';
    to_lowercase(en);
    
    printf("Enter lesson number: ");
    scanf("%d", &lesson);
    flushInput();
    
    for(int i = 0; i < count; i++){
        if(strcmp(dictionary[i].czech, cz) == 0){
            printf("The word is already in the dictionary");
            return;
        }
    }
        


    FILE *f = fopen(filename, "a");
    if(f == NULL){
        perror("There was an error opening the file.");
            return;
    }

    fprintf(f,"%s;%s;%d;\n", cz, en, lesson);
    fclose(f);

    printf("Word was successfully added\n");
}

//Function that tests the user from the amount of words they input and keeps track of their success rate
void randomTest(Word dictionary[], int count){
    int amount;
    int correct = 0;
    char answer[N];
    int random_num;
    int used[count];

    printf("How many words do you want to test (max %d) \n", count);
    scanf("%d", &amount);
    flushInput();

    if(amount > count){
        printf("There is not enough words.\n");
        return;
    }

    for(int i = 0; i < count; i++){
        used[i] = 0;
    }
    srand(time(NULL));

    for(int i = 0; i < amount; i++){
        do{
            random_num = rand() % count;
        } while (used[random_num] == 1);

        used[random_num] = 1;

        printf("Translate the word: \"%s\":  ", dictionary[random_num].czech);
        fgets(answer,N,stdin);
        answer[strcspn(answer, "\n")] = '\0';
        to_lowercase(answer);

        if(strcmp(answer, dictionary[random_num].english) == 0){
            printf("Correct!\n");
            correct++;
        } else {
            printf("\nIncorrect, the correct answer is \"%s\" \n", dictionary[random_num].english);
        }
    }

    printf("\nQuiz complete! Statistics:\n");
    printf("Total questions: %d\n", amount);
    printf("Correct answers: %d\n", correct);
    printf("Incorrect answers: %d\n", amount - correct);
    printf("Success rate: %.2f%%\n", (float)correct / amount * 100);
}

//Function that either edits a word or deletes a word in the struct and rewrites the file accordingly
void EditWords(const char *filename, Word dictionary[], int count){
    char choice;
    char word[N];
    int lesson;

    printf("Do you wanna delete or edit? (d/e)\n");
    scanf("%c", &choice);
    flushInput();

    if(choice == 'e'){
    printf("Input the czech word of the word you want to edit: \n");
    fgets(word,N,stdin);
    word[strcspn(word, "\n")] = '\0';
    to_lowercase(word);

    for(int i = 0; i < count; i++){
        if(strcmp(dictionary[i].czech, word) == 0){
            printf("Editing word: \"%s\"  \n",word); 
            
            printf("Enter a new cz word: ");
            fgets(dictionary[i].czech,N,stdin);
            dictionary[i].czech[strcspn(dictionary[i].czech, "\n")] = '\0';
            to_lowercase(dictionary[i].czech);

            printf("Enter the english word: ");
            fgets(dictionary[i].english,N,stdin);
            dictionary[i].english[strcspn(dictionary[i].english,"\n")] = '\0';
            to_lowercase(dictionary[i].english);

            printf("Enter the lesson number: ");
            scanf("%d", &dictionary[i].lecture);
            flushInput();

            FILE *f = fopen(filename,"w");
            if(f == NULL){
                perror("Error opening the file");
                return;
            }

            for(int j = 0; j < count; j++){
                fprintf(f, "%s;%s;%d;\n", dictionary[j].czech, dictionary[j].english, dictionary[j].lecture);
            }
            fclose(f);
            return;
            
        }
        }
        printf("Word not found...\n");
    } else if (choice == 'd') {
        printf("Input the czech word you want to delete: ");
        fgets(word,N,stdin);
        word[strcspn(word, "\n")] = '\0';
        to_lowercase(word);

        for(int i = 0; i < count; i++){
            if(strcmp(dictionary[i].czech,word) == 0){
                for(int j = i; j < count - 1;j++){
                    dictionary[j] = dictionary[j + 1];
                }
                count--;

                FILE *f = fopen(filename, "w");
                if(f == NULL){
                    perror("There was an error while opening the file");
                    return;
                }
                for(int j = 0; j < count;j++){
                    fprintf(f, "%s;%s;%d;\n",dictionary[j].czech, dictionary[j].english, dictionary[j].lecture);
                }
            fclose(f);
            printf("Word \"%s\" was deleted successfully.\n",word);
            return;
            }
        }
    printf("Word not found...");
    } else {
        printf("Wrong input\n");
        return;
    }
}
