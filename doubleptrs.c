#include <stdio.h>

int main(void) {
    char *myStrings[10] = {"COP 3223", "CDA 3103", "CIS 4004", "CIS 3990", "CIS 4991", "COP 4600", "COP 5611", "COP 4910", "COP 4331", "CS Advising"};
    /*
    myStrings[3] : Array of arrays, which is also an array of pointers, should point to 4th string
    myStrings[9][5]:  Should point to 6th character of 9th string.
    */
    printf("String #3 using indexing: %s\n", myStrings[3]);
    /*
    myStrings:  contains the memory address of the first entry of the string array
        Example:  first entry is at address 0x100
    myStrings + 3:  contains the memory address of the first entry plus 3 bytes.
        Example:  We're looking at 0x100 + 3 or 0x103, or the fourth entry.
    */
    printf("String #3 using pointer math: %s\n", *(myStrings+3));
}