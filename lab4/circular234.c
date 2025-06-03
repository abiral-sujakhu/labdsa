#include <stdio.h>
#include <stdlib.h>

int *queue;
int SIZE;
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if queue is full
int isFull() {
    return (rear + 1) % SIZE == front;
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
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
        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Peek operation
void peek() {
    if (isEmpty())
        printf("Queue is Empty\n");
    else
        printf("Front Element: %d\n", queue[front]);
}

// Display queue in normal order
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Display queue in reverse order without modifying
void displayReverse() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue in Reverse: ");
    int i = rear;
    while (1) {
        printf("%d ", queue[i]);
        if (i == front) break;
        i = (i - 1 + SIZE) % SIZE;
    }
    printf("\n");
}

// Count elements in queue
int count() {
    if (isEmpty()) return 0;
    if (rear >= front)
        return rear - front + 1;
    return SIZE - front + rear + 1;
}

// Main function with Assignments 2, 3, and 4
int main() {
    printf("Enter queue size: ");
    scanf("%d", &SIZE);

    queue = (int*)malloc(SIZE * sizeof(int));
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
