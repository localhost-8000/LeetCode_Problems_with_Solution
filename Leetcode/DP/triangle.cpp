// Problem link:- https://leetcode.com/problems/triangle

// DP solution..
class Solution {
private:
    vector<vector<int>> dp;
    void createDP(int r, int c) {
        for(int i=0; i<=r; ++i) {
            vector<int> temp;
            for(int j=0; j<=c; ++j)
                temp.push_back(-1);
            dp.push_back(temp);
        }
    }
public:
    int steps(vector<vector<int>>& triangle, int n, int j) {
        if(n == triangle.size()) {
            return 0;
        }
        if(dp[n][j] != -1) return dp[n][j];
        
        dp[n][j] = triangle[n][j];
        dp[n][j] += min(steps(triangle, n+1, j), steps(triangle, n+1, j+1));
        return dp[n][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        createDP(triangle.size(), triangle.size());
        return steps(triangle, 0, 0);
    }
};


// space optimized SC:- O(N)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        int dp[n];
        for(int i=0; i<n; ++i) dp[i] = triangle[n-1][i];
        
        for(int r=n-2; r >= 0; --r) {
            for(int c=0; c <= r; ++c) {
                dp[c] = min(dp[c], dp[c+1]) + triangle[r][c];
            }
        }
        
        return dp[0];
    }
};
