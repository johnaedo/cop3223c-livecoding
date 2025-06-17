#include <stdio.h>

#define PI 3.1415

const float pi = 3.1415;

int testForTruth(int x) {
    return x;
}

int main(void) 
{

    int myvarDecimal = 13u;
    int myvarBinary = 0b1101l;
    int myvarOctal = 015u;
    int myvarHexadecimal = 0xDl;

    float myvarSingle = 10.78;
    float myvarSingleStandard = 1.078E-1;
    float myvarSingleHuge = 1.078E25;
    float myvarSingleTiny = 1.078E-25;

    double myvarDouble = 1.5;
    double myvarDoubleHuge = 1.07E75;
    double myvarDoubleTiny = 1.07E-75;

    char answer = 'x';
    char tab = '\t';
    char newline = '\n';

    // printf("\"myvarDecimal\" is %d\n", myvarDecimal);
    // printf("myvarBinary is %d\n", myvarBinary);
    // printf("myvarOctal is %d\n", myvarOctal);
    // printf("myvarHexadecimal is %d\n", myvarHexadecimal);

    // printf("myvarSingle %.3f\n", myvarSingle);
    // printf("myvarSingleHuge %f\n", myvarSingleHuge);
    // printf("myvarSingleHuge %E\n", myvarSingleHuge);

    float mypi = 3.1415;

    
    int radius = 10;
    float area1 = PI * radius * radius;
    float area2 = 3.1415 * radius * radius;
    float area3 = pi * radius * radius;

    mypi = 3;
    
    // printf("area1: %f\n", area1);
    // printf("area2: %f\n", area2);
    // printf("area3: %f\n", area3);

    int x = 25;
    int y = 7;

    int a = 0;
    int b = 12;

    // if (a) {
    //     printf("a is true\n");
    // } else {
    //     printf("a is false\n");
    // }

    // if (0) {
    //     printf("0 is true\n");
    // } else {
    //     printf("0 is false\n");
    // }


    // if (!(b > 15 && a < 12)) {
    //     printf("b is not greater than 15\n");
    //     printf("a may or may not be less than 12\n");
    // }



    // printf("x modulo y is %d\n", x % y);
    // x++;
    // y++;
    // printf("x++ is %d\n", x);
    // printf("y-- is %d\n", y);
    // printf("new x is %d\n", x);
    // printf("new y is %d\n", y);

    /*
    1001
    1100  &
    ------
    1000

    1001
    1100 |
    -------
    1101

    1001
    1100 ^
    -----
    0101
    
    */
    printf("1001 & 1100 is %d\n", 0b1001 & 0b1100 );
    printf("1001 | 1100 is %d\n", 0b1001 | 0b1100 );
    printf("1001 ^ 1100 is %d\n", 0b1001 ^ 0b1100 );
    printf("!1001 is %d\n", ~0b1001);



    return(0);
}
