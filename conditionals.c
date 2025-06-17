#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alwaysFalseZero() {
    return 0;
}

int* alwaysFalseNull() {
    return NULL;
}

int alwaysTrue() {
    int truthy = rand() % 100 + 1;
    printf("Truthy:  %d\n", truthy);
    return truthy;
}

int main(void) {
    srand(time(0));
    printf("Testing falsiness.\n");
    if (alwaysFalseZero()) {
        printf("We shouldn't see this ever.\n");
    } else {
        printf("Zero is falsy.\n");
    }
    printf("This is after the first IF, always executes.\n");
    if (alwaysFalseNull()) {
        printf("We shouldn't see this, either.\n");
    } else {
        printf("NULL is falsy.\n");
    }
    printf("Testing truthiness.\n");
    if (alwaysTrue() > 75) {
        printf("Upper quartile.\n");
    } else if (alwaysTrue() > 50) {
        printf("Upper half.\n");
    } else {
        printf("Lower half.\n");
    }
}
