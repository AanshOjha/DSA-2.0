#include <stdio.h>
#define MAX 20

int a[MAX] = {5,1,4,2,3};

void merge(int low, int mid, int high) {
    int temp[MAX];
    int left = low, right = mid + 1, k = low;

    while (left <= mid && right <= high) {
        if (a[left] < a[right]) {
            temp[k] = a[left];
            k++;
            left++;
        } else {
            temp[k] = a[right];
            k++;
            right++;
        }
    }

    // Copy remaining elements from left half
    while (left <= mid) {
        temp[k] = a[left];
        k++;
        left++;
    }

    // Copy remaining elements from right half
    while (right <= high) {
        temp[k] = a[right];
        k++;
        right++;
    }

    // Inserting from temp to original array
    for (left = low; left <= high; left++) {
        a[left] = temp[left];
    }
}

void mergesort(int low, int high) {
    // When array has 1 element
    if (low >= high) 
        return;

    int mid = (low + high) / 2;

    // Sort first half
    mergesort(low, mid);

    // Sort second half
    mergesort(mid + 1, high);

    // Merge both half
    merge(low, mid, high);
}

void quickSort(int arr[], int low, int hi) {
    if (low < hi)  {   

        int start = low;
        int end = hi;
        int mid = low + (hi-low) / 2;
        int pivot = arr[mid];

        while (start <= end) {
            while (arr[start] < pivot) {
                start++;
            }
            while (arr[end] > pivot) {
                end--;
            }

            if (start <= end) {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }

        quickSort(arr, low, end);
        quickSort(arr, start, hi);
    }
}

void main() {
    // int arr[] = {5,4,3,2,1};
    // // mergeSort(arr, 8);
    // int arr_len = 5;
    // quickSort(arr, 0, arr_len-1);
    // for (int i = 0; i <=arr_len-1; i++) printf("%d ", arr[i]);
    int n, i;

    // printf("Enter the number of elements: ");
    // scanf("%d", &n);

    // printf("Enter the elements:\n");
    // for (i = 0; i < n; i++) {
    //     scanf("%d", &a[i]);
    // }

    // printf("Unsorted list:\n");
    // for (i = 0; i < n; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");

    mergesort(0, 5 - 1);

    printf("Sorted list:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}