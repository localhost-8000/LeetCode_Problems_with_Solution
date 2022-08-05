// Problem link:- https://leetcode.com/problems/combination-sum-iv/
// Difficulty:- Medium

// copy of coin change problem.. O(n * target)
class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int target) {
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        
        int ans = 0;
        
        for(int &num : nums) {
            if(num <= target) ans += solve(nums, dp, target - num);
        }
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        
        return solve(nums, dp, target);
    }
};
