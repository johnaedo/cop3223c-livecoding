#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    /* This program only takes an integer and a string
    Usage:
    args <int> <string>
    Example:
    args 7 "My String"
    */
    if (argc != 3) {
        printf("This program takes 2 arguments.\n");
        printf("Usage:  args <int> <string>\n");
        exit(-1);
    }
    int strlength = strlen(argv[2]);
    char message[strlength];
    int count;
    strcpy(message, argv[2]);
    count = atoi(argv[1]);
    printf("Count: %d, Message: %s\n", count, message);
}