// Problem link:  https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
// Difficulty: Hard

// Key point: How to optimally break a element and which direction would be suited to start the iteration.


// Optimal solution
// TC: O(n)  SC: O(1)
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = size(nums);
        long long replacementCount = 0;

        for (int i=n-2; i>=0; --i) {
            int curr = nums[i];
            int prevBound = nums[i+1];

            if (curr <= prevBound) {
                continue;
            }
            int cnts = curr / prevBound;
            if (curr % prevBound != 0) {
                cnts++;
            }

            replacementCount += cnts - 1;
            nums[i] = nums[i] / cnts;
        }

        return replacementCount;
    }
};