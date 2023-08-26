// Problem link:- 

// naive approach...
class Solution {
public:
    int uniquePath(vector<vector<int>>& obstacleGrid, int r, int c) {
        int m = obstacleGrid.size();
        int n = m ? obstacleGrid[0].size() : 0;
        
        if(r == m - 1 && c == n - 1 && obstacleGrid[r][c] == 0) return 1;
        
        if(obstacleGrid[r][c] == 1) return 0;
        
        int downPath = 0;
        int rightPath = 0;
        
        if(r + 1 < m && obstacleGrid[r + 1][c] == 0) {
            downPath += uniquePath(obstacleGrid, r + 1, c);
        }
        
        if(c + 1 < n && obstacleGrid[r][c + 1] == 0) {
            rightPath += uniquePath(obstacleGrid, r, c + 1);
        }
        
        return rightPath + downPath;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return uniquePath(obstacleGrid, 0, 0);
    }
};


// DP solution...
class Solution {
    vector<vector<int>> dp;
public:
    int uniquePath(vector<vector<int>>& obstacleGrid, int r, int c) {
        int m = obstacleGrid.size();
        int n = m ? obstacleGrid[0].size() : 0;
        
        if(r == m - 1 && c == n - 1 && obstacleGrid[r][c] == 0) return 1;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        if(obstacleGrid[r][c] == 1) return dp[r][c] = 0;
        
        int downPath = 0;
        int rightPath = 0;
        
        if(r + 1 < m && obstacleGrid[r + 1][c] == 0) {
            downPath += uniquePath(obstacleGrid, r + 1, c);
        }
        
        if(c + 1 < n && obstacleGrid[r][c + 1] == 0) {
            rightPath += uniquePath(obstacleGrid, r, c + 1);
        }
        
        return dp[r][c] = rightPath + downPath;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = m ? obstacleGrid[0].size() : 0;
        
        dp.resize(m);
        for(int i=0; i<m; ++i) dp[i].resize(n, -1);
        
        return uniquePath(obstacleGrid, 0, 0);
    }
};
