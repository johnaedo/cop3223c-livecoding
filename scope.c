#include <stdio.h>

int myGlobalInt = 5;

int doStuff(int x) {
    int myLocal = 6;
    int y = x;
    printf("myGlobalInt from doStuff() - %d\n", myGlobalInt);
    printf("myLocal is %d\n", myLocal);
    printf("x from doStuff() - %d\n", x);
    printf("y from doStuff - %d\n", y);
    {
        int y = 12;
        printf("y from inside the IF block - %d\n", y);
    }
    printf("y outside the IF block - %d\n", y);
}

int main(void) {
    doStuff(5);
}