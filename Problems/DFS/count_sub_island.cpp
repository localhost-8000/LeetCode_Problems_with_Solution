// Problem link:- https://leetcode.com/problems/count-sub-islands/
// Difficulty:- Medium

class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int r = grid1.size();
        int c = r ? grid1[0].size() : 0;
        
        if(i < 0 || j < 0 || i >= r || j >= c) return;
        if(grid1[i][j] == 0 || grid2[i][j] == 0) return;
        
        grid2[i][j] = 0;
        
        dfs(grid1, grid2, i+1, j);
        dfs(grid1, grid2, i-1, j);
        dfs(grid1, grid2, i, j+1);
        dfs(grid1, grid2, i, j-1);
        
        return;
    }
    
    void normal_dfs(vector<vector<int>>& grid, int i, int j) {
        int r = grid.size();
        int c = r ? grid[0].size() : 0;
        
        if(i < 0 || j < 0 || i >= r || j >= c) return;
        if(grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        
        normal_dfs(grid, i+1, j);
        normal_dfs(grid, i-1, j);
        normal_dfs(grid, i, j+1);
        normal_dfs(grid, i, j-1);
        
        return;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r = grid1.size();
        int c = r ? grid1[0].size() : 0;
        
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(grid2[i][j] && !grid1[i][j]) normal_dfs(grid2, i, j);
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(grid2[i][j] && grid1[i][j]) {
                    ans++;
                    dfs(grid1, grid2, i, j);
                }
            }
        }
        
        return ans;
    }
};
