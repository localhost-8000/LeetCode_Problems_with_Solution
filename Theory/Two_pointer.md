# Two Pointer Approach

The two-pointer approach is a popular technique used to solve a variety of algorithmic problems efficiently. It involves using two pointers that typically start at different positions and then traverse the data structure towards each other, following certain rules based on the problem's requirements. This approach is commonly used to optimize time and space complexity, often reducing it from O(n^2) to O(n) or even O(n log n).

## Basic Idea

1. Initialize two pointers, usually named "left" and "right," at different positions in the array.
2. Move the pointers towards each other while following problem-specific conditions.
3. Adjust the pointers' movement based on comparisons between values at their positions.
4. Repeat until the pointers meet or fulfill certain conditions, solving the problem in the process.

## Pseudocode Example

Here's a generic pseudocode template that illustrates the two-pointer approach:

```c++
function twoPointerAlgorithm(array):
    leftPointer = 0
    rightPointer = array.length - 1
    
    while leftPointer < rightPointer:
        currentPair = (array[leftPointer], array[rightPointer])
        
        if condition(currentPair):
            // Take action based on the condition
            leftPointer = leftPointer + 1 
            or
            rightPointer = rightPointer - 1
        else:
            // Take action based on the condition
            leftPointer = leftPointer + 1 
            or
            rightPointer = rightPointer - 1
```

## Famous Two Pointer problems

- [**Two Sum**](https://leetcode.com/problems/two-sum/)
- [**Reverse String**](https://leetcode.com/problems/reverse-string/)
- [**Container with Most Water**](https://leetcode.com/problems/container-with-most-water/)
- [**Remove Duplicates from Sorted Array**](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
- [**3 Sum**](https://leetcode.com/problems/3sum/)
