#include <stdio.h>
#include <stdlib.h>

int *queue;
int SIZE;
int front = -1, rear = -1;

// Check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Enqueue operation
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is Full\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
    }
}

// Peek operation
void peek() {
    if (isEmpty())
        printf("Queue is Empty\n");
    else
        printf("Front Element: %d\n", queue[front]);
}

// Count elements in the queue
int count() {
    return isEmpty() ? 0 : (rear - front + 1);
}

// Display queue from front to rear
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Display queue in reverse order without modifying it
void displayReverse() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue in Reverse: ");
        for (int i = rear; i >= front; i--) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function implementing assignments 2, 3, and 4
int main() {
    printf("Enter queue size: ");
    scanf("%d", &SIZE);

    queue = (int *)malloc(SIZE * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assignment 3: Dynamic enqueueing
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    // Wrap-around enqueue after dequeue
    dequeue();         // Removes 10
    enqueue(50);       // Fills space
    enqueue(60);       // May show full if queue is full
    display();

    // Assignment 2: peek(), isEmpty()
    peek();
    printf("Queue is %sempty.\n", isEmpty() ? "" : "not ");
    printf("Total elements in queue: %d\n", count());

    // Assignment 4: Display in reverse
    displayReverse();

    // Cleanup
    free(queue);
    return 0;
}
