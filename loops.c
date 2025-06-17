#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDie(void) {
    return rand() % 6 + 1;
}

int printDice(int a, int b) {
    printf("Die 1: %d\tDie 2: %d\n", a, b);
}


int main(void) {
    beginning:
    srand(time(0));


    int die1 = 0;
    int die2 = 0;

    die1 = rollDie();
    die2 = rollDie();
    printDice(die1, die2);
    while (! (die1 == 6 && die2 == 6)) {
        die1 = rollDie();
        die2 = rollDie();
        printDice(die1, die2);
        if (die1 + die2 == 7) {
            printf("Lucky 7!\n");
        }
        printf("Insignificant rolls.\n");

    }
    printf("End of Loop!\n");

    for(;;) {
         printf("This goes on forever!\n");
     }

    while(1) {
        printf("This also goes on forever!\n");
    }


}