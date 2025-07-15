#include <stdio.h>

// Sequential Search
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// Binary Search (requires sorted array)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high)/2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100], n, key, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    printf("\nSearch Menu:\n");
    printf("1. Sequential Search\n");
    printf("2. Binary Search (Array must be sorted!)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = sequentialSearch(arr, n, key);
            break;
        case 2:
            result = binarySearch(arr, n, key);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    if (result != -1)
        printf("Element found at index %d (position %d)\n", result, result + 1);
    else
        printf("Element not found!\n");

    return 0;
}
