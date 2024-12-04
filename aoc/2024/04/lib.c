#include "lib.h"
#include <stdio.h>

int possible_directions[8][2] = {
    {0,1}, {0,-1},
    {1,0}, {-1,0},
    {1,1}, {1,-1},
    {-1,1}, {-1,-1},
};

int get_width(const char *filename){

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("There was an error while opening the file..\n");
        return -1;
    }
    
    char line_buffer[buffer];
    if(fgets(line_buffer, sizeof(line_buffer), f)) {
        int width = strlen(line_buffer);
        if (line_buffer[width - 1] == '\n') {
            width--;
        }
        fclose(f);
        return width;
    }
    fclose(f);
    return 0;
}

int get_height(const char *filename) {
    
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("There was an error while opening the file..\n");
    }
    
    int height = 0;
    char line_buffer[buffer];
    while (fgets(line_buffer, sizeof(line_buffer), f)) {
        height++;
    }
    fclose(f);
    return height;
}

    

int total_matches(const char *filename) {
    int matches = 0;
    char *word = "XMAS";
    int width = get_width(filename);
    int word_length = strlen(word);
    int height = get_height(filename);
    
    char grid[height][width + 1];

    FILE *f = fopen(filename, "r");
    if (f == NULL){
        perror("There was an error while opening the file");
    }

    for (int i = 0; i < height; i++) {
        if (fgets(grid[i], width + 2,f)){
            if (grid[i][width] == '\n'){
                grid[i][width] = '\0';
            }
        }
    }
    fclose(f);

    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            for (int direction = 0; direction < 8; direction++) {
                int temp_match = 1;
                for (int i = 0; i < word_length; i++) {
                    int temp_row = row + i * possible_directions[direction][0];
                    int temp_col = column + i * possible_directions[direction][1];

                    if (temp_row < 0 || temp_row >= height || temp_col < 0 || temp_col >= width) {
                        temp_match = 0;
                        break;
                    }

                    if (grid[temp_row][temp_col] != word[i]) {
                        temp_match = 0;
                        break;
                    }
                }
                if (temp_match == 1) {
                    matches++;
                }
            }
        }
    }
    return matches;
}
