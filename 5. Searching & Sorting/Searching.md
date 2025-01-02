# Searching Algos

## Linear Search

### Functioning 
* Given Target element and array,
* Iterates over the array elements
* If current element == target, return the element

### Time Complexity
#### O(N)
Makes N/2 Comparisons. Constants are ignored.

### Space Complexity
#### O(1)
No new things are created.

### When to use 
When array is small

### Syntax
```
static int linearSearch(int[] arr, int target) {
  for (int i = 0; i< arr.length; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}
```


## Binary Search

### Functioning

* Upper and lower bounds are set to specify range of Searching.
* A current index variable == (lowerBound + upperBound)/2
* While loop is ran until lowerBound < upperBound
* If currIndex == target, return. If not, divide range to half.
* If target < currIndex, then target is b/w lowerBound and currIndex.

So, upperBound= currIndex
* If target > currIndex, then target is b/w currIndex and upperBound.

So, lowerBound= currIndex 
* Now again If currIndex == target.


### Characteristic
* Array must be sorted.
* Search times very faster.
* Insertion / deletion slow, as sorted array is needed. 

### Time Complexity
#### O(logN)
No. of steps (s), No of Elements (N) then
__s = logN base 10__

__logN (base 10) x 3.22 = logr (base 2)__

### Space Complexity
#### O(1)
No new things are created.


### When to use
* When array is large
* Eg. Used in employee records, as hiring/ lay off employee less than accessing their data.



### Syntax
```
    static int simpleBinarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length-1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
 
            if (arr[mid] == target) {
                return mid;
            }
            
            if (target > arr[mid]) {
                // Search in the right 
                start = mid + 1;
            } else if (target < arr[mid]) {
                // search in the left
                end = mid - 1;
            }
        }
        return -1;
    }
```