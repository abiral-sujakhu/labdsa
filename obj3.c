#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int val) {
    if (top < SIZE - 1) {
        stack[++top] = val;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0;
}

int evaluatePrefix(char prefix[]) {
    int i, op1, op2, result;
    char ch;

    // Start from the end of the expression
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        ch = prefix[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            push(ch - '0');  // convert char digit to int
        } else {
            op1 = pop();
            op2 = pop();

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1;
            }
            push(result);
        }
    }

    return pop();
}

int main() {
    char prefix[SIZE];

    printf("Enter Prefix Expression: ");
    fgets(prefix, SIZE, stdin);
    prefix[strcspn(prefix, "\n")] = '\0'; // remove newline

    int result = evaluatePrefix(prefix);

    printf("Result: %d\n", result);
    return 0;
}
