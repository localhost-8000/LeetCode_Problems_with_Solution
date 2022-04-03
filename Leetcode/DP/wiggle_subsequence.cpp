// Problem link:- https://leetcode.com/problems/wiggle-subsequence

// Brute force approach..
class Solution {
public:
    int solve(vector<int>& nums, int idx, bool isInc) {
        int cnt = 0;
        for(int i=idx+1; i<nums.size(); ++i) {
            if((isInc && nums[i] > nums[idx]) || (!isInc && nums[i] < nums[idx])) {
                cnt = max(cnt, 1 + solve(nums, i, !isInc));
            }
        }
        return cnt;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        return 1 + max(solve(nums, 0, true), solve(nums, 0, false));
    }
};

// Optimized dp solution...
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        vector<int> dpInc(n, 0);
        vector<int> dpDec(n, 0);
        
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(nums[i] > nums[j]) {
                    dpInc[i] = max(dpInc[i], dpDec[j] + 1);
                } else if(nums[i] < nums[j]) {
                    dpDec[i] = max(dpDec[i], dpInc[j] + 1);
                }
            }
        }
        
        return 1 + max(dpInc[n - 1], dpDec[n - 1]);
    }
};

// Greedy approach :- https://github.com/Ankur-9598/LeetCode_Problems_with_Solution/blob/main/Leetcode/Greedy/wiggle_subsequence.cpp
