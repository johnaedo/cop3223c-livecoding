#include <stdio.h>

void printArray(int * myArray, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\n", myArray[i]);
    }
}

int * copyArray(int *myArray, int size) {
    static int copy[5];
    for(int i = 0; i < size; i++) {
        copy[i] = myArray[i];
    }
    return copy;


}

void printArray2(int myArray[], int size) {
    for(int i = 0; i < size; i++) {
        // address = base_address + sizeof(int) * i
        // address = base_address + (4 * i)
        // example:  i = 2
        // address = base_address + 8
        printf("%d\n", myArray[i]);
    }
}

int main(void) {
    int myIntArray1[5] = {0, 1, 3, 5, 7};
    int myIntArray2[] = {0, 1, 3, 5, 17, 14, 201, 13};
    char myName[10] = "Hello";
    float myFloatArray[] = {0.1, 0.2, 0.3};
    int *myPointer;

    printf("What is myIntArray1: %p\n", myIntArray1);
    int myMultiDimArray[2][3] = {
        0, 1, 2, 3, 4, 5
    };
    printf("Second row, second column: %d\n", myMultiDimArray[1][1]);
    printArray(myIntArray1, 5);
    printArray(myIntArray2, 8);
    myPointer = copyArray(myIntArray1, 5);
    for (int i=0; i < 5; i++) {
        printf("orig - %d\t", myIntArray1[i]);
        printf("copy - %d\n", myPointer[i]);
    }
}