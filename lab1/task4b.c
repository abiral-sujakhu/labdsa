#include <stdio.h>

void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 10;
    printf("Before swapByReference - a: %d, b: %d\n", a, b);
    swapByReference(&a, &b);
    printf("After swapByReference - a: %d, b: %d\n", a, b);
    return 0;
}
