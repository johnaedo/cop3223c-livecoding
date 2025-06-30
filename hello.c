/* hello.c for COP 3223C */
#include <stdio.h>


void printHello(void *data) {
	printf("Hello, %s!\n", (char*) data);
}

int main(void) {
	printHello("COP 3223C");
}
