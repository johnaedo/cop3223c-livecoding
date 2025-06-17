#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int currentTime = 0;
    printf("Current Time: %d\n", currentTime);
    int randomVal = 0;
    for(int i=0; i<5; i++) {
        currentTime = time(0);
        srand(currentTime);
        randomVal = rand();
        printf("%d\n", randomVal);
    }
}