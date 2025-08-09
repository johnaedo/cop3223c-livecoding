#include <stdio.h>

int main(void) {
    char num;
    char hex;
    char c;
    printf("Enter a number between 1 and 10: ");
    // num = fgetc(stdin);
    scanf("%c", &num);
    while((c = getchar()) != '\n' && c != EOF);
    printf("Enter a letter between A and F: ");
    // hex = fgetc(stdin);
    scanf("%c", &hex);
    while((c = getchar()) != '\n' && c != EOF);
    printf("You entered %c and %c\n", num, hex);
}