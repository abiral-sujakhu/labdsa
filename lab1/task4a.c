#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue - a: %d, b: %d\n", a, b);
}

int main() {
    int a = 5, b = 10;
    printf("Before swapByValue - a: %d, b: %d\n", a, b);
    swapByValue(a, b);
    printf("After swapByValue - a: %d, b: %d\n", a, b);
    return 0;
}
