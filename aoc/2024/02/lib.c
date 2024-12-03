#include "lib.h"
#include <stdio.h>
#include <string.h>

int safe_reps(const char *filename) {
    const int buffer = 32;
    int safe_lines = 0;
    char line[buffer];


    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("There was an error while opening the file...\n");
        return 101;
    }

    while(fgets(line, buffer, f)){
        int valid = 1, monotone = 0;
        int previous_num = 0;
        char *element = strtok(line, " \n");

        while(element != NULL){
            int current_num = atoi(element);

            if(previous_num != 0){
                int difference = abs(current_num - previous_num);

                if(difference > 3 || difference < 1){
                    valid = 0;
                    break;
                }
            if(current_num > previous_num){
                if (monotone == 0) monotone = 1;
                else if (monotone == -1) monotone = 0;
            }else if(current_num < previous_num){
                if (monotone == 0) monotone = -1;
                else if (monotone == 1) monotone = 0;
            }
            }
            
            previous_num = current_num;
            element = strtok(NULL, " \n");
        }
        if (valid && monotone != 0){
            safe_lines++;
        }
    }
    fclose(f);
    return safe_lines;
}
