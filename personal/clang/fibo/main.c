#include <stdio.h>

void fibo(int repeats) {
    int prev = 0;
    int current = 1;
    
    for (int i = 0; i < repeats; i++){
        printf("%d ", prev);
        int temp = prev + current;
        prev = current;
        current = temp;
    }

}

int fibo2 (int n) {
    if (n == 0) {
        return 0;
    }
}

int main() {
    int repeats;
    
    printf("How many repeats: \n");
    scanf("%d", &repeats);

    fibo(repeats);

    return 0;
}
