#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top < SIZE - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top >= 0 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        } else if (isOperator(ch)) {
            while (top >= 0 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top >= 0) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter Infix Expression: ");
    fgets(infix, SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // remove newline

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
