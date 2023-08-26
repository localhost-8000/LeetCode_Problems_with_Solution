// Problem link:- https://leetcode.com/problems/coin-change/
// Difficulty:- Medium

// Brute force recursion...
class Solution {
public:
    int solve(vector<int>& coins, int amount, int i) {
        int n = coins.size();
        if(i >= n || amount < 0) return INT_MAX;
        if(amount == 0) return 0;
        
        int pick_curr = solve(coins, amount - coins[i], i);
        if(pick_curr == INT_MAX) return solve(coins, amount, i + 1);
        
        return min(pick_curr + 1, solve(coins, amount, i + 1));
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount, 0);
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};

// Optimized DP approach..
class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        int n = coins.size();
        
        if(i >= n || amount < 0) return INT_MAX;
        if(amount == 0) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int pick_curr = solve(coins, amount - coins[i], i, dp);
        
        if(pick_curr == INT_MAX) return dp[i][amount] = solve(coins, amount, i + 1, dp);
        
        return dp[i][amount] = min(pick_curr + 1, solve(coins, amount, i + 1, dp));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        int ans = solve(coins, amount, 0, dp);
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};
