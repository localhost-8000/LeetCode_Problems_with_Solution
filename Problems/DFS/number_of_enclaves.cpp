// Problem link:- https://leetcode.com/problems/number-of-enclaves/
// Difficulty:- Medium

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int r = grid.size();
        int c = r ? grid[0].size() : 0;
        
        if(i < 0 || i >= r) return;
        if(j < 0 || j >= c) return;
        if(grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = r ? grid[0].size() : 0;
        
        int ans_cnt = 0;
      
        // for column boundary..
        for(int i=0; i<r; ++i) {
            if(grid[i][0]) dfs(grid, i, 0);
            if(grid[i][c-1]) dfs(grid, i, c-1);
        }
       
        // for row boundary..
        for(int j=0; j<c; ++j) {
            if(grid[0][j]) dfs(grid, 0, j);
            if(grid[r-1][j]) dfs(grid, r-1, j);
        }
        
        // count enclosed components..
        for(int i=1; i<r; ++i) {
            for(int j=1; j<c; ++j) {
                if(grid[i][j]) {
                    ans_cnt++;
                }
            }
        }
        
        return ans_cnt;
    }
};
