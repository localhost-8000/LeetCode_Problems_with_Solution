// Problem link:- https://leetcode.com/problems/number-of-islands

// dfs approach..
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        
        if(x < 0 || x >= m) return;
        if(y < 0 || y >= n) return;
        
        // if cell is visited or water return...
        if(grid[x][y] == '0' || grid[x][y] == 'v') return;
        
        // mark current cell as visited..
        grid[x][y] = 'v';
        
        dfs(grid, x, y+1);    // recurse right...
        dfs(grid, x+1, y);    // recurse bottom...
        dfs(grid, x, y-1);    // recurse left...
        dfs(grid, x-1, y);    // recurse top...
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int numIsland = 0;
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                
                // if cell is not visited and not water...
                if(grid[i][j] != 'v' && grid[i][j] != '0') {
                    
                    numIsland++;  // increment island count..
                    dfs(grid, i, j);
                }
            }
        }
        return numIsland;
    }
};
