#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

void enqueue(int value, int priority) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next && temp->next->priority <= priority)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue() {
    if (!front) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued: %d (Priority: %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

void displayQueue() {
    struct Node* temp = front;
    printf("Priority Queue: ");
    while (temp) {
        printf("[%d|P:%d] -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueue(10, 2);
    enqueue(30, 1);
    enqueue(20, 3);
    displayQueue();

    dequeue();
    displayQueue();

    return 0;
}
