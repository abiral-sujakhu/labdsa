#include <stdio.h>
#define SIZE 100

int list[SIZE];
int n = 0;

void insert(int pos, int value) {
    if (pos < 0 || pos > n || n == SIZE) {
        printf("Invalid position or overflow.\n");
        return;
    }
    for (int i = n; i > pos; i--) {
        list[i] = list[i - 1];
    }
    list[pos] = value;
    n++;
}

void delete(int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        list[i] = list[i + 1];
    }
    n--;
}

void display() {
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    insert(0, 10); // insert at beginning
    insert(1, 20); // insert at end
    insert(1, 15); // insert at specific position
    display();

    delete(0); // delete from beginning
    delete(n-1); // delete from end
    display();

    return 0;
}
