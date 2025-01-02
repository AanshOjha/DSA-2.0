#include <stdio.h>

int binarySearch(int arr[], int arr_len, int target) {
    int start = 0;
    int end = arr_len - 1;
    while (start <= end) {      // if only <, will miss if target is at end.
        int mid = start + (end-start)/2;

        if (arr[mid] == target) 
            return mid;
        else if (arr[mid] < target)     // target is in right side
            start = mid + 1;
        else if (arr[mid] > target)     // target in left side
            end = mid - 1;
    }
    
    return -1;
}

int linearSearch(int arr[], int arr_len, int target) {
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

void main() {
    int sorted_arr[] = {23, 45, 67, 78, 90};
    int arr[] = {45, 78, 90, 23, 67};

    // int index = linearSearch(sorted_arr, 5, 78);
    int index = binarySearch(sorted_arr, 5, 90);
    printf("\nIndex: %d", index);
}