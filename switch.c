#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));
    int choice = (rand() % 10) + 1;
    printf("Die roll: %d\n", choice);
    switch (choice) {
    case 1:
        printf("%d\n", choice);
        break;
    case 2:
        printf("%d\n", choice);
        break;
        // do stuff
    case 3:
        printf("%d\n", choice);
        break;
        // do stuff
    case 4:
        printf("%d\n", choice);
        break;
        // do stuff
    case 5:
        printf("%d\n", choice);
        break;
        // do stuff
    case 6:
        printf("%d\n", choice);
        break;
        // do stuff
    default:
        switch(choice) {
            case 7:
                printf("%d is lucky, but not valid.\n", choice);
                break;
            case 8:
                printf("%d is lucky to some, but still not valid.\n", choice);
                break;
            case 9:
                printf("%d is the square of 3, but still not valid.\n", choice);
                break;
            case 10:
                printf("%d - MAX VALUE!\n", choice);
                break;
            default:
                printf("ERROR!\n");
        }
    }

}