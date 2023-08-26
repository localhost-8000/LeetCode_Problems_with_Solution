// Problem link:- https://leetcode.com/problems/target-sum
// Difficulty:- Medium

// Brute force O(2^n)
class Solution {
public:
    int solve(vector<int>& arr, int target, int n) {
        if(n == 0) return target == 0 ? 1 : 0;
        
        int pl = target - arr[n - 1];
        int sb = target + arr[n - 1];
        
        return solve(arr, pl, n - 1) + solve(arr, sb, n - 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;
        
        
        return solve(nums, target, n);
    }
};

// DP optimized solution
class Solution {
public:
    int solve(vector<int>& arr, int target, int n, vector<unordered_map<int, int>>& dp) {
        if(n == 0) return target == 0 ? 1 : 0;
        
        if(dp[n].find(target) != dp[n].end()) return dp[n][target];
        
        int pl = target - arr[n - 1];
        int sb = target + arr[n - 1];
        
        return dp[n][target] = solve(arr, pl, n - 1, dp) + solve(arr, sb, n - 1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<unordered_map<int, int>> dp(n + 1);
        
        return solve(nums, target, n, dp);
    }
};
