// Problem link:- https://leetcode.com/problems/delete-operation-for-two-strings/
// Difficulty:- Medium

// Recursive DP...
class Solution {
    vector<vector<int>> dp;
public:
    int solve(string word1, string word2, int i, int j) {
        int n1 = word1.length();
        int n2 = word2.length();
        
        if(i == n1 && j == n2) return 0;
        if(i == n1 || j == n2) return i == n1 ? n2 - j : n1 - i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, i+1, j+1);
        
        return dp[i][j] = min(solve(word1, word2, i+1, j), solve(word1, word2, i, j+1)) + 1;
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        
        dp.resize(n1, vector<int>(n2, -1));
        
        return solve(word1, word2, 0, 0);
    }
};

// Tabulation DP..
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        dp[0][0] = 0;
        
        for(int i=1; i<=n1; ++i) dp[i][0] = i;
        for(int i=1; i<=n2; ++i) dp[0][i] = i;
        
        for(int i=1; i<=n1; ++i) {
            for(int j=1; j<=n2; ++j) {
                if(word1[i-1] == word2[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            }
        }
        
        return dp[n1][n2];
    }
};

// space optimized dp...
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        
        vector<int> dp(n1 + 1, 0);
        
        for(int i=0; i<=n1; ++i) {
            
            vector<int> temp(n2 + 1, 0);
            
            for(int j=0; j<=n2; ++j) {
                if(i == 0 || j == 0) temp[j] = i + j;
                
                else if(word1[i-1] == word2[j-1]) 
                    temp[j] = dp[j-1];
                
                else temp[j] = min(temp[j-1], dp[j]) + 1;
            }
            
            dp = temp;
        }
        
        return dp[n2];
    }
};
