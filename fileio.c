#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chop(char *str) {
    /*
    str[len - 1] :  Last character, which we expect is '\n'
    str[len] : '\0'

    To get rid of the '\n', replace is with '\0'
    str[len - 1] = '\0'

    */
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Replace newline with null terminator
    }
}

int main(void) {
    char filename[50];
    char line[256];
    printf("Please enter filename to read: ");
    fgets(filename, 50, stdin);
    chop(filename);
    printf("[%s]\n", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);  // Print each line
    }
    fclose(fp);
}