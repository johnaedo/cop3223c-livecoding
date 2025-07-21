#include <stdio.h>
#include <stdlib.h>

void recurse(int count) {
    void *block;
    char buffer[1000];
    block = malloc(1024*1024*1024);
    printf("Iteration %d\n", count);
    recurse(count+1);
};

int main(void) {
    recurse(1);
    return 0;
}