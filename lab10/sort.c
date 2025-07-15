#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(&arr[i], &arr[minIdx]);
    }
}

// Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j = i;
            while (j >= gap && arr[j - gap] > temp)
                arr[j] = arr[j - gap], j -= gap;
            arr[j] = temp;
        }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int L[MAX], R[MAX];
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = j = 0; k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Radix Sort
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[MAX], count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i]/exp)%10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Print function
void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX], n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\nSorting Algorithms Menu:\n");
    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Shell Sort\n");
    printf("5. Quick Sort\n6. Merge Sort\n7. Radix Sort\n8. Heap Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: bubbleSort(arr, n); break;
        case 2: insertionSort(arr, n); break;
        case 3: selectionSort(arr, n); break;
        case 4: shellSort(arr, n); break;
        case 5: quickSort(arr, 0, n - 1); break;
        case 6: mergeSort(arr, 0, n - 1); break;
        case 7: radixSort(arr, n); break;
        case 8: heapSort(arr, n); break;
        default: printf("Invalid choice!\n"); return 1;
    }

    printArray(arr, n);
    return 0;
}
