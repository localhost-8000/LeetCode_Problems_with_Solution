// Problem link:- https://leetcode.com/problems/pacific-atlantic-water-flow/
// Difficulty:- Medium


int dirs[5] = {1, 0, -1, 0, 1};

class Solution {
    int r, c;
    vector<vector<int>> ans;
    vector<vector<bool>> pacific, atlantic;
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) { 
        if(visited[i][j]) return;
        
        visited[i][j] = true;
        
        if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
        
        for(int p=1; p<5; ++p) {
            int x = i + dirs[p-1], y = j + dirs[p];
            if(x >= 0 && y >= 0 && x < r && y < c && heights[x][y] >= heights[i][j]) 
                dfs(heights, visited, x, y);
        }
        
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r = heights.size();
        c = r ? heights[0].size() : 0;
        
        pacific.resize(r, vector<bool>(c, false));
        atlantic = pacific;
        
        for(int i=0; i<r; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, c-1);
        }
        
        for(int j=0; j<c; ++j) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, r-1, j);
        }
        
        return ans;
    }
};
