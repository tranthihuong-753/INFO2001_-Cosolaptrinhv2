#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int arr[] = {5, 2, 8, 12, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort
    clock_t start_time = clock();
    bubbleSort(arr, n);
    clock_t end_time = clock();

    printf("Bubble Sort Output:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double bubble_execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Selection Sort
    start_time = clock();
    selectionSort(arr, n);
    end_time = clock();

    printf("Selection Sort Output:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double selection_execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Bubble Sort Execution Time: %f seconds\n", bubble_execution_time);
    printf("Selection Sort Execution Time: %f seconds\n", selection_execution_time);

    return 0;
}
