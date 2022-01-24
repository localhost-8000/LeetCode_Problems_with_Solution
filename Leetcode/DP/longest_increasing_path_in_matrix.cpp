// Problem link:- https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
    vector<vector<int>> dp;
public:
    int cntPath(vector<vector<int>>& matrix, int r, int c) {
        int row = matrix.size();
        int col = row ? matrix[0].size() : 0;
     
        if(r < 0 || r >= row || c < 0 || c >= col) return 0;
        
        if(dp[r][c] != -1) return dp[r][c];
        if(matrix[r][c] == -1) return dp[r][c] = 0;
        
        int curr_num = matrix[r][c];
        matrix[r][c] = -1;
        
        int curr_len = 1;
        
        // move right..
        if((c + 1 < col) && (curr_num < matrix[r][c + 1])) {
            int right_max_path = 1 + cntPath(matrix, r, c+1);
            curr_len = max(curr_len, right_max_path);
        }
        
        // move down..
        if(r + 1 < row && curr_num < matrix[r + 1][c]) {
            int down_max_path = 1 + cntPath(matrix, r + 1, c);
            curr_len = max(curr_len, down_max_path);
        }
        
        // move left..
        if(c - 1 >= 0 && curr_num < matrix[r][c - 1]) {
            int left_max_path = 1 + cntPath(matrix, r, c - 1);
            curr_len = max(curr_len, left_max_path);
        }
        
        // move up..
        if(r - 1 >= 0 && curr_num < matrix[r - 1][c]) {
            int up_max_path = 1 + cntPath(matrix, r - 1, c);
            curr_len = max(curr_len, up_max_path);
        }
        
        matrix[r][c] = curr_num;
        
        return dp[r][c] = curr_len;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = row ? matrix[0].size() : 0;
        
        dp.resize(row);
        for(int i=0; i<row; ++i) {
            dp[i].resize(col, -1);
        }
        
        int ans = 0;
        for(int i=0; i<row; ++i) {
            for(int j = 0; j<col; ++j) {
                ans = max(ans, cntPath(matrix, i, j));
            }
        }
        
        return ans;
    }
};
