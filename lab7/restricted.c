#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Deque {
    int arr[MAX];
    int front;
    int rear;
};

void initDeque(struct Deque* dq) {
    dq->front = dq->rear = -1;
}

int isFull(struct Deque* dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(struct Deque* dq) {
    return dq->front == -1;
}

void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Insertion
void insertFront(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
}

void insertRear(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
}

// Deletion
void deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from rear: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

// Main
int main() {
    struct Deque dq;
    initDeque(&dq);

    int choice, type, value;

    printf("Choose Deque Type:\n");
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    scanf("%d", &type);

    while (1) {
        printf("\n------ Menu ------\n");
        printf("1. Insert at Rear\n");
        if (type == 2) printf("2. Insert at Front\n"); // Output restricted
        printf("3. Delete from Front\n");
        if (type == 1) printf("4. Delete from Rear\n"); // Input restricted
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(&dq, value);
            break;
        case 2:
            if (type == 2) {
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(&dq, value);
            } else {
                printf("Invalid for Input Restricted Deque\n");
            }
            break;
        case 3:
            deleteFront(&dq);
            break;
        case 4:
            if (type == 1) {
                deleteRear(&dq);
            } else {
                printf("Invalid for Output Restricted Deque\n");
            }
            break;
        case 5:
            display(&dq);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
