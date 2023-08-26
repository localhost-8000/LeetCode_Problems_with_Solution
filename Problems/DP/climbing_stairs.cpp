// Problem link:- https://leetcode.com/problems/climbing-stairs

// Naive method..TC:- O(2^n)
class Solution {
public:
    int climbStairs(int n) {
        if(n < 0) {
            return 0;
        }
        if(n == 0) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Optimised approach using DP...TC:- O(n) SC:- O(n)
// Top down approach
class Solution {
public:
    int findCount(int n, vector<int>& dp) {
        if(n < 0) {
            return 0;
        }
        if(n == 0) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = findCount(n-1, dp) + findCount(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return findCount(n, dp);
    }
};

// bottom up approach
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
