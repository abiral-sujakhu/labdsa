#include <stdio.h>

int factorialIterative(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial (iterative) of %d is %d\n", num, factorialIterative(num));
    return 0;
}
