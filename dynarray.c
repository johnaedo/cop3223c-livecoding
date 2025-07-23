#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct record {
    int i;
    char *name;
} record_t;

int main(int argc, char **argv) {
    int array_size = atoi(argv[1]);
    record_t *record = malloc(sizeof(record_t) * array_size);
    for (int i = 0; i < array_size; i++) {
        record[i].i = (rand() % 10) + 1;
    }
    for (int j = 0; j < array_size; j++) {
        printf("%d\n", record[j].i);
    }
    free(record);
}