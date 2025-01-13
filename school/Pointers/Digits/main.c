#include "headers/lib.h"
#include <stdio.h>

int main() {
    int num = 0;
    int end = 0;
    int sum = 0;
    int digits = 0;
    int choice = 0;


    printf("Enter a number: ");
    scanf("%d", &num);
    flush();
    
    while(end == 0) {
        printf("\nWhat do you wanna do?\n 1) Print sum and digits\n 2)\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            get_digits(num, &digits);
            add_digits(num, digits, &sum);
            
            printf("The sum of the digits is %d\n", sum);
            printf("The number has %d digits\n", digits);
            break;
        }
    }
    
    return 0;
}
