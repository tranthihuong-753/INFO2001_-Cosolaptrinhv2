#include <stdio.h>

int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  // Tr? v? ch? s? c?a ph?n t? n?u t?m th?y
        }
    }
    return -1;  // Tr? v? -1 n?u không t?m th?y
}

int binary_search(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            return mid;  
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int linear_result = linear_search(arr, n, x);
    int binary_result = binary_search(arr, n, x);

    if (linear_result != -1) {
        printf("Linear Search: Phan tu  %d duoc tim thay tai chi so  %d.\n", x, linear_result);
    } else {
        printf("Linear Search: Phan tu  %d khong tim thay trong mang .\n", x);
    }

    if (binary_result != -1) {
        printf("Binary Search: Phan tu  %d duoc tim thay tai chi so  %d.\n", x, binary_result);
    } else {
        printf("Binary Search: Phan tu  %d khong tim thay trong mang .\n", x);
    }

    return 0;
}
