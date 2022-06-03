// Problem link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Difficulty:- Medium

// Using DFS.. gives TLE
class Solution {
    int ans;
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int cost) {
        int n = grid.size();
        
        if(i < 0 || j < 0 || i >= n || j >= n) return;
        
        if(i == n-1 && j == n-1 && grid[i][j] == 0) {
            ans = min(ans, cost+1);
            return;
        }
        
        if(grid[i][j] == 1) return;
        
        grid[i][j] = 1;
        
        dfs(grid, i-1, j-1, cost+1);
        dfs(grid, i-1, j, cost+1);
        dfs(grid, i-1, j+1, cost+1);
        dfs(grid, i, j+1, cost+1);
        dfs(grid, i+1, j+1, cost+1);
        dfs(grid, i+1, j, cost+1);
        dfs(grid, i+1, j-1, cost+1);
        dfs(grid, i, j-1, cost+1);
        
        grid[i][j] = 0;
        
        return;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        ans = INT_MAX;
        
        dfs(grid, 0, 0, 0);
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

// Using BFS.. optimal
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n == 1 && grid[0][0] == 0) return 1;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        
        queue<pair<int, int>> bfs;
        bfs.push({0, 0});
        
        while(!bfs.empty()) {
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();
            
            for(int i=0; i<8; ++i) {
                int xx = x + dirs[i].first;
                int yy = y + dirs[i].second;
                
                if(xx >= 0 && yy >= 0 && xx < n && yy < n && grid[xx][yy] == 0) {
                    grid[xx][yy] = grid[x][y] + 1;
                    bfs.push({xx, yy});
                }
            }
            
        }
        
        if(grid[n-1][n-1] == 0) return -1;
        
        return grid[n-1][n-1] + 1;
    }
};
