// Problem link:- https://leetcode.com/problems/last-stone-weight-ii/
// Difficulty:- Medium

// O(N * sumOfArray)...
class Solution {
public:
    int solve(vector<int>& stones, int i, int diff, vector<vector<int>>& dp) {
        int n = stones.size();
        int pos_diff = abs(diff);
        
        if(i == n) return pos_diff;
        if(dp[i][pos_diff] != -1) return dp[i][pos_diff];
        
        int pick_l = solve(stones, i+1, diff + stones[i], dp);
        int pick_r = solve(stones, i+1, diff - stones[i], dp);
        
        return dp[i][pos_diff] = min(pick_l, pick_r);
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(begin(stones), end(stones), 0);
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        return solve(stones, 0, 0, dp);
    }
};
