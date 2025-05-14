#include <stdio.h>
float squarert(float x){
    float xa = x;
    float xb = xa / 2;

    while (xb < xa) {
        xa = xb; 
        xb = (xa + x / xa) / 2;
    }
    return xa;
}

int main(){
    float input;
    printf("Input a number: ");
    scanf("%f", &input);
    printf("\n");
    

    printf("The square root of your number is %.3f\n", squarert(input));

    return 0;
}
