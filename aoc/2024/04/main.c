#include "lib.h"

int main() {
    const char *filename = "input.txt";
    
    printf("The heigth is %d\n", get_height(filename));
    //Part 1
    printf("The word was found %d times", total_matches(filename));
    //Part 2

    return 0;
}       
