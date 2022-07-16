// Problem link:- https://leetcode.com/problems/out-of-boundary-paths
// Difficulty:- Medium


class Solution {
    int row, col, MOD;
    int dp[51][51][51];
public:
    int dfs(int i, int j, int move) {
        if(i < 0 || i >= row || j < 0 || j >= col) return 1;
        if(move == 0) return 0;
        
        if(dp[i][j][move] != -1) return dp[i][j][move];
        
        long long up = dfs(i-1, j, move-1);
        long long right = dfs(i, j+1, move-1);
        long long down = dfs(i+1, j, move-1);
        long long left = dfs(i, j-1, move-1);
        
        return dp[i][j][move] = (up + right + down + left) % MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        row = m, col = n;
        MOD = 1e9 + 7;
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(startRow, startColumn, maxMove);
    }
};
