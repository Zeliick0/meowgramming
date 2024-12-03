#include "lib.h"

int main() {
const char *filename = "input.txt";

int length = get_length(filename);
int *left = malloc(length * sizeof(int));
int *right = malloc(length * sizeof(int));

fillarrays(left, right, length);
sortarray(left, length);
sortarray(right, length);

//Part 1
printf("The distance between the lists is %d\n", distance(left, right, length));
//Part 2
printf("The score is %d\n", matches(left,right,length));

free(left);
free(right);

return 0;
}
