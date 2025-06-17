#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* head = NULL;

void insertAtBeginning(int value) {
    struct DNode* newNode = malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int value) {
    struct DNode* newNode = malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteFromBeginning() {
    if (!head) return;
    struct DNode* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
}

void deleteFromEnd() {
    if (!head) return;
    struct DNode* temp = head;
    if (!temp->next) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void displayForward() {
    struct DNode* temp = head;
    printf("Forward: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward() {
    struct DNode* temp = head;
    if (!temp) return;
    while (temp->next)
        temp = temp->next;
    printf("Backward: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAtBeginning(10);
    insertAtEnd(40);
    displayForward();
    displayBackward();

    deleteFromBeginning();
    deleteFromEnd();
    displayForward();
    displayBackward();

    return 0;
}
