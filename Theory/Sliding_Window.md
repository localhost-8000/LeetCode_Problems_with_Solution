# Sliding Window Technique

The **Sliding Window Technique** is a common algorithmic strategy used to solve problems that involve arrays or sequences. It's particularly useful when you need to efficiently find or process a subset of elements from an array that meets certain criteria.

## How It Works

The idea behind the sliding window technique is to maintain a "window" or a subarray within the original array that satisfies the problem's requirements. The window's size can vary based on the problem's constraints. As you iterate through the array, you adjust the window's boundaries according to the problem's rules.

The key benefit of the sliding window technique is that it reduces the time complexity by avoiding redundant calculations. Instead of re-calculating the properties of each subarray from scratch, you update the window by adding or removing an element at one end while sliding it to the other end.

## Use Cases

The sliding window technique is commonly used in problems involving strings, arrays, or sequences, where you need to:

- Find the minimum or maximum value in a subarray of a given size.
- Find the longest or shortest subarray that satisfies a certain condition.
- Detect patterns or substrings that meet specific criteria.

## Steps to Apply Sliding Window Technique

1. Define the window's size or constraints based on the problem's requirements.
2. Initialize pointers to mark the start and end of the window.
3. Iterate through the array using the end pointer.
4. Adjust the window based on the problem's criteria and constraints.
5. Update the solution based on the current window's contents.
6. Move the window by advancing the start pointer and continue the iteration.
7. Repeat steps 3 to 6 until the end pointer reaches the end of the array.

## Example

Let's consider the problem of finding the maximum sum of a subarray of length `k` in an array `arr`:

```c++
int maxSubarraySum(const vector<int>& arr, int k) {
    int n = arr.size();
    int maxSum = INT_MIN;
    int windowSum = 0;

    for (int end = 0; end < n; ++end) {
        windowSum += arr[end];

        if (end >= k - 1) {
            maxSum = max(maxSum, windowSum);
            windowSum -= arr[end - (k - 1)];
        }
    }

    return maxSum;
}
```

In this example, we maintain a sliding window of size k, and as we slide the window to the right, we update the window_sum to get the sum of the current subarray. The max_sum keeps track of the maximum subarray sum encountered.

## Famous sliding window problems

- [**Maximum Subarray**](https://leetcode.com/problems/maximum-subarray/)
- [**Fruit Into Baskets**](https://leetcode.com/problems/fruit-into-baskets/)
- [**Max Consecutive Ones III**](https://leetcode.com/problems/max-consecutive-ones-iii/)
- [**Minimum Size Subarray Sum**](https://leetcode.com/problems/minimum-size-subarray-sum/)
- [**Find All Anagrams in a String**](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
- [**Subarrays with K Different Integers**](https://leetcode.com/problems/subarrays-with-k-different-integers/)
- [**Longest Substring Without Repeating Characters**](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Conclusion
The sliding window technique is a powerful strategy to efficiently solve array-related problems. By maintaining a fixed-size window and updating it as you iterate through the array, you can optimize your algorithms and solve complex problems with improved time complexity.