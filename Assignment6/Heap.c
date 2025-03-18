#include<stdio.h>

void heapify(int n, int arr[], int i) {
    int l, r, t, max = i;
    l = 2 * i + 1;  // left child index
    r = 2 * i + 2;  // right child index

    // Check if left child is larger than root
    if (l < n && arr[l] > arr[max]) {
        max = l;
    }

    // Check if right child is larger than the largest so far
    if (r < n && arr[r] > arr[max]) {
        max = r;
    }

    // If largest is not root, swap and heapify the affected sub-tree
    if (max != i) {
        t = arr[i];
        arr[i] = arr[max];
        arr[max] = t;

        // Recursively heapify the affected sub-tree
        heapify(n, arr, max);
    }
}

void heapsort(int arr[], int n) {
    int t, i;

    // Build the heap (rearrange the array)
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(n, arr, i);
    }

    // One by one extract elements from heap
    for (i = n - 1; i >= 0; i--) {
        // Move current root to end
        t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        // Call heapify on the reduced heap
        heapify(i, arr, 0);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    heapsort(arr, n);

    printf("The sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Added space for better readability
    }
    printf("\n");

    return 0;
}
