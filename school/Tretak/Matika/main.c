#include "lib.h"

int main() {
    srand(time(NULL));

    float correctState = 0;
    for (int i = 0; i < 100; i++) {

        int counter = 0;
        for(int j = 0; j < 5; j++){
        int num = randomNum();
            if (num == 8) {
                counter++;
            }

            if (counter >= 3) {
                correctState++;
            }
        }
    }

    printf("The chance is %f", correctState / 100);
    return 0;
}
