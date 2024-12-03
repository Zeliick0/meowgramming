#include "lib.h"
#include <stdio.h>
#include <string.h>
#define buffer 32

int is_monotone(int prev, int cur){
    if (cur > prev) {
        return 1;
    }

    if (cur < prev) {
        return -1;
    }
    return 0;
}

int safe_reps(const char *filename) {
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
                int difference = abs(previous_num - current_num);

              if(difference > 3 || difference < 1){
                    valid = 0;
                    break;
                }
              int current_monotone = is_monotone(previous_num, current_num);
              if (current_monotone != 0) {
                    if (monotone == 0) {
                        monotone = current_monotone;
                    }
                    else if (monotone != current_monotone) {
                        valid = 0;
                        break;
                    }
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
