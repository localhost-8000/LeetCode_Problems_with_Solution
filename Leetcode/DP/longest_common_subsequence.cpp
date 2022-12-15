// Problem link:- https://leetcode.com/problems/longest-common-subsequence
// Difficulty:- Medium


// Brute force recursion
class Solution {
public:
    int recur(int i, int j, const string& s1, const string& s2, const int n1, const int n2) {
        if(i >= n1 || j >= n2) return 0;

        char a = s1[i], b = s2[j];
        
        if(a == b) {
            return 1 + recur(i+1, j+1, s1, s2, n1, n2);
        }

        int l = recur(i+1, j, s1, s2, n1, n2);
        int r = recur(i, j+1, s1, s2, n1, n2);
        
        return max(l, r);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        return recur(0, 0, text1, text2, n1, n2);
    }
};

// DP Optimization --> Memoization
class Solution {
public:
    int recur(int i, int j, const string& s1, const string& s2, const int n1, const int n2, vector<vector<int>>& dp) {
        if(i >= n1 || j >= n2) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        char a = s1[i], b = s2[j];

        if(a == b) return dp[i][j] = 1 + recur(i+1, j+1, s1, s2, n1, n2, dp);

        int l = recur(i+1, j, s1, s2, n1, n2, dp);
        int r = recur(i, j+1, s1, s2, n1, n2, dp);
        
        return dp[i][j] = max(l, r);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return recur(0, 0, text1, text2, n1, n2, dp);
    }
};


// DP Optimization --> Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        int dp[n1 + 1][n2 + 1];
        
        for(int i=0; i<=n1; ++i) dp[i][0] = 0;
        for(int j=0; j<=n2; ++j) dp[0][j] = 0;

        for(int i=1; i<=n1; ++i) {
            for(int j=1; j<=n2; ++j) {
                char a = text1[i-1], b = text2[j-1];
                if(a == b) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n1][n2];
    }
};
