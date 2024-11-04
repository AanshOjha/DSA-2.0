# Collections
* Main collections used in DSA are:

## 1. Array
* An array is a data structure that stores a collection of elements, same data type, in a contiguous memory location. Each element can be accessed by its index.

```java
int[] numbers = new int[3];              // Array with default values of 0
int[] nums = {1, 2, 3};                  // Literal array creation
int[][] multiDim = {{1, 2}, {3, 4}};     // Multi-dimensional array

```

*  Fixed size after creation.
*  Accesses to elements of arrays are done in constant time, be it 1st element or 5th `(O(1) time complexity)`.

### Key methods:
* `Arrays.sort(array)` - Sorts array elements in ascending order.
* `Arrays.binarySearch(array, key)` - Searches for key in sorted array (O(log n) complexity).
* `Arrays.fill(array, value)` - Fills all elements with a specific value.
* `array.length` - Returns the size of the array.
* `System.arraycopy(src, srcPos, dest, destPos, length)` - Copies array elements.

## 2. Collections
A set of classes and interfaces for storing and manipulating groups of objects.

* List - Ordered collection allowing duplicates (e.g., ArrayList, LinkedList).
* Set - Unordered collection without duplicates (e.g., HashSet, TreeSet).
* Map - Collection of key-value pairs (e.g., HashMap, TreeMap).

### Key methods:

* `Collections.sort(list)` - Sorts list elements in ascending order.
* `Collections.reverse(list)` - Reverses order of elements in a list.
* `Collections.shuffle(list)` - Randomly shuffles elements in a list.
* `Collections.max(collection)` / `Collections.min(collection)` - Finds max/min element.

## 3. Lists
Ordered collection that allows duplicates, part of the Collections framework.
* Can add/delete elements.
  
```java
List<Integer> list = new ArrayList<>();
```

* ArrayList - Resizable array-backed implementation, offers fast access by index.
* LinkedList - Doubly-linked list, efficient for frequent insertions/deletions.

### Key Methods:
* `list.add(element)` - Adds element to the list.
* `list.get(index)` - Retrieves element at specified index.
* `list.remove(index)` / list.remove(object) - Removes element by index or value.
* `list.set(index, element)` - Updates element at a specified index.
* `list.size() `- Returns the number of elements in the list.
