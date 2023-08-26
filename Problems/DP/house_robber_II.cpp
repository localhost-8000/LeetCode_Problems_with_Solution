// Problem link:- https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int findMaxAmount(const vector<int>& nums, bool initial, int k, vector<int>& dp) {
        if(k >= nums.size()) return 0;
        if(k == (nums.size() - 1) && initial) return 0;
        
        if(dp[k] != -1) return dp[k];
     
        int includeCurrent = nums[k] + findMaxAmount(nums, initial, k+2, dp);
        int ignoreCurrent = findMaxAmount(nums, initial, k+1, dp);
        
        dp[k] = max(includeCurrent, ignoreCurrent);
        
        return dp[k];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, -1);
        int ans1 = findMaxAmount(nums, true, 0, dp);
        
        for(int &x : dp) x = -1;
        
        int ans2 = findMaxAmount(nums, false, 1, dp);
        
        return max(ans1, ans2);
    }
};
