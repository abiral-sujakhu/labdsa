#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create polynomial
struct Node* createPoly() {
    struct Node* head = NULL, *tail = NULL;
    int coeff, exp, n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &exp);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = NULL;

        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL, *tail = NULL;
    while (poly1 && poly2) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;
        if (poly1->exp > poly2->exp) {
            newNode->coeff = poly1->coeff;
            newNode->exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            newNode->coeff = poly2->coeff;
            newNode->exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            newNode->coeff = poly1->coeff + poly2->coeff;
            newNode->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (result == NULL)
            result = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Append remaining terms
    while (poly1) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = poly1->coeff;
        newNode->exp = poly1->exp;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        poly1 = poly1->next;
    }

    while (poly2) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = poly2->coeff;
        newNode->exp = poly2->exp;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        poly2 = poly2->next;
    }

    return result;
}

// Function to display polynomial
void displayPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Main function
int main() {
    printf("Enter first polynomial:\n");
    struct Node* poly1 = createPoly();
    printf("Enter second polynomial:\n");
    struct Node* poly2 = createPoly();

    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    struct Node* result = addPoly(poly1, poly2);
    printf("Sum: ");
    displayPoly(result);

    return 0;
}
