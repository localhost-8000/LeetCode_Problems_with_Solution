// Problem link:- https://leetcode.com/problems/where-will-the-ball-fall/
// Difficulty:- Medium


class Solution {
    int r, c;
public:
    int findFallingCol(vector<vector<int>>& grid, int row, int prev, int curr, int next) {
        if(prev < 0 && next >= c) return -1;
        
        int curr_col = grid[row][curr];
        int prev_col = prev >= 0 ? grid[row][prev] : -2;
        int next_col = next < c ? grid[row][next] : -2;
        
        if(row == r-1) {
            if(curr_col == prev_col && curr_col == -1) return prev;
            if(curr_col == next_col && curr_col == 1) return next;
            return -1;
        }
        
        if(curr_col == prev_col && curr_col == -1) return findFallingCol(grid, row+1, prev-1, prev, curr);
        
        if(curr_col == next_col && curr_col == 1) return findFallingCol(grid, row+1, curr, next, next+1);
        
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        r = grid.size();
        c = r == 0 ? 0 : grid[0].size();
        
        vector<int> ans(c);
        
        for(int i=0; i<c; ++i) ans[i] = findFallingCol(grid, 0, i-1, i, i+1);
        
        return ans;
    }
};
