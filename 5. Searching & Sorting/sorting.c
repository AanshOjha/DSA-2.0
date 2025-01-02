#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i <= n-2; i++) {
        int min_index = i;

        // Find min Index
        for (int j = i; j <= n-1; j++) {
            if (arr [j] < arr[min_index])
                min_index = j;
        }

        // Swapping
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i <= n-1; i++){

        for (int j = 0; j <= n-i-2; j++) {

            // If current element greater than next element, SWAP
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

void optimizedBubble(int arr[], int n) { 
    int swapped = 0; // False
    for (int i = 0; i <= n-1; i++){
        for (int j = 0; j <= n-i-2; j++) {

            // If current element greater than next element, SWAP
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
                swapped = 1;
            }
        }

        printf("%d iteration done!\n", i+1);
        // Not single swap after 1st iteration, means array sorted
        if (swapped == 0) {
            break;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 0; i <= n-1; i++) {
        for (int j = i; j >= 1 && arr[j-1] > arr[j]; j--) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;     
        }
    }
}

void main() {
    int arr[] = {5,1,4,2,3};
    // int arr[] = {1,2,3,4,5};
    int n = 5;
    insertionSort(arr, n);

    for (int i = 0; i <= n-1; i++) {
        printf("%d ", arr[i]);
    }

}