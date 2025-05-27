#include <stdio.h>

// Non-Tail Recursive Factorial
int factorial_non_tail(int n) {
    if (n == 0)
        return 1;
    return n * factorial_non_tail(n - 1);
}

// Tail Recursive Factorial
int factorial_tail(int n, int acc) {
    if (n == 0)
        return acc;
    return factorial_tail(n - 1, acc * n);
}

// Non-Tail Recursive Sum
int sum_non_tail(int n) {
    if (n == 0)
        return 0;
    return n + sum_non_tail(n - 1);
}

// Tail Recursive Sum
int sum_tail(int n, int acc) {
    if (n == 0)
        return acc;
    return sum_tail(n - 1, acc + n);
}

// Non-Tail Recursive Fibonacci
int fib_non_tail(int n) {
    if (n <= 1)
        return n;
    return fib_non_tail(n - 1) + fib_non_tail(n - 2);
}

// Tail Recursive Fibonacci
int fib_tail(int a, int b, int n) {
    if (n == 0)
        return a;
    return fib_tail(b, a + b, n - 1);
}

// Tower of Hanoi
void tower_of_hanoi(int n, char source, char target, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    tower_of_hanoi(n - 1, source, aux, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    tower_of_hanoi(n - 1, aux, target, source);
}

// Tail Recursive GCD (Challenge)
int gcd_tail(int a, int b) {
    if (b == 0)
        return a;
    return gcd_tail(b, a % b);
}

// Main function demonstrating all implementations
int main() {
    int n = 5;

    // Factorial
    printf("Factorial (Non-Tail) of %d: %d\n", n, factorial_non_tail(n));
    printf("Factorial (Tail) of %d: %d\n", n, factorial_tail(n, 1));

    // Sum
    printf("Sum (Non-Tail) of first %d numbers: %d\n", n, sum_non_tail(n));
    printf("Sum (Tail) of first %d numbers: %d\n", n, sum_tail(n, 0));

    // Fibonacci
    printf("Fibonacci (Non-Tail) at position %d: %d\n", n, fib_non_tail(n));
    printf("Fibonacci (Tail) at position %d: %d\n", n, fib_tail(0, 1, n));

    // Tower of Hanoi with 3 disks
    printf("\nTower of Hanoi for 3 disks:\n");
    tower_of_hanoi(3, 'A', 'C', 'B');

    // GCD challenge (HCF)
    int a = 48, b = 18;
    printf("\nTail Recursive GCD of %d and %d: %d\n", a, b, gcd_tail(a, b));

    return 0;
}
