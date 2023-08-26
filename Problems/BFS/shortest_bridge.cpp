// Problem link:- https://leetcode.com/problems/shortest-bridge/
// Difficulty:- Medium

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        int r = grid.size(); 
        int c = r ? grid[0].size() : 0;
        
        if(i < 0 || j < 0 || i == r || j == c || grid[i][j] == 0 || grid[i][j] == 2) return;
        
        grid[i][j] = 2;
        q.push({i, j});
        
        dfs(grid, i+1, j, q);
        dfs(grid, i-1, j, q);
        dfs(grid, i, j+1, q);
        dfs(grid, i, j-1, q);
        
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int r = grid.size(); 
        int c = r ? grid[0].size() : 0;
        
        queue<pair<int, int>> bfs;
        bool flag = false;
        
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, bfs);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = INT_MAX;
        
        while(!bfs.empty()) {
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();
            
            for(int i=0; i<4; ++i) {
                int xx = x + dirs[i][0];
                int yy = y + dirs[i][1];
                
                if(xx >= 0 && yy >= 0 && xx < r && yy < c) {
                    if(grid[xx][yy] == 0) {
                        grid[xx][yy] = 1 + grid[x][y];
                        bfs.push({xx, yy});
                    } else if(grid[xx][yy] == 1) {
                        return grid[x][y] - 2;
                    }
                }
            }
        }
        
        return ans;
    }
};
