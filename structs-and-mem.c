#include <stdio.h>

struct CartesianPoint {
    int x;
    int y;
};

int main(void) {
    struct CartesianPoint myPoint; // roughly like CartesianPoint myPoint = new CartesianPoint()
    printf("Address of myPoint: %p\n", &myPoint);
}