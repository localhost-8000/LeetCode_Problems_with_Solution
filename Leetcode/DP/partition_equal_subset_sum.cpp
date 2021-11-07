// Problem link:- https://leetcode.com/problems/partition-equal-subset-sum/

// first approach
class Solution {
public:
    int checkPartition(vector<int>& nums, int ls, int rs, int n, vector<vector<int>>& dp) {
        if(ls == rs) {
            return 1;
        }
        if(ls == 0 || n == -1) {
            return 0;
        }
        if(dp[n][ls] != -1) {
            return dp[n][ls];
        }
        return dp[n][ls] = checkPartition(nums, ls-nums[n], rs+nums[n], n-1, dp) || checkPartition(nums, ls, rs, n-1, dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(int i=0; i<nums.size(); ++i) {
            total_sum += nums[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(total_sum + 1, -1));
        return checkPartition(nums, total_sum, 0, n - 1, dp);
    }
};

// little bit more modification..
class Solution {
public:
    int checkIsSumExists(vector<int>& nums, int sum, int n, vector<vector<int>>& dp) {
        if(sum == 0) {
            return 1;
        }
        if(n <= 0) {
            return 0;
        }
        if(dp[n][sum] != -1) {
            return dp[n][sum];
        }
        dp[n][sum] = checkIsSumExists(nums, sum, n - 1, dp);
        if(nums[n - 1] <= sum) {
            dp[n][sum] |= checkIsSumExists(nums, sum - nums[n - 1], n - 1, dp);
        }
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        for(int i=0; i<nums.size(); ++i) {
            total_sum += nums[i];
        }
        
        if(total_sum % 2 == 1) {
            return false;
        }
        
        int sum = total_sum / 2;
        
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        return checkIsSumExists(nums, sum, n, dp);
    }
};
