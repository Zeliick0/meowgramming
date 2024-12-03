#include "lib.h"

int main() {
const char *filename = "input.txt";

int length = get_length(filename);
int *left = malloc(length * sizeof(int));
int *right = malloc(length * sizeof(int));

fillarrays(left, right, length);
sortarray(left, length);
sortarray(right, length);

printf("The distance between the lists is %d", distance(left, right, length));


free(left);
free(right);

return 0;
}
