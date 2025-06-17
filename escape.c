#include <stdio.h>

int main(void) {
    char str1[100] = "hello, dear";
    char str2[200] = "hello, \
    this is a multiline string\
    that you can see demoed here\
    and this is finally\
    the end";
    
    char str3[100] = "hello, " "d" "ear";

    printf("str1:  %s\n", str1);
    printf("str2:  %s\n", str2);
    printf("str3:  %s\n", str3);
}