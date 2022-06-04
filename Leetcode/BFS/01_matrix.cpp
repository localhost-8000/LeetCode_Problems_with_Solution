// Problem link:- https://leetcode.com/problems/01-matrix/
// Difficulty:- Medium

// Using BFS...
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = r ? mat[0].size() : 0;
        
        vector<vector<int>> ans(r, vector<int>(c, INT_MAX));
        queue<pair<int, int>> bfs;
        
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    bfs.push({i, j});
                }
            }
        }
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        while(!bfs.empty()) {
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();
            
            for(int i=0; i<4; ++i) {
                int xx = x + dirs[i][0];
                int yy = y + dirs[i][1];
                
                if(xx >= 0 && yy >= 0 && xx < r && yy < c) {
                    if(ans[xx][yy] > ans[x][y] + 1) {
                        ans[xx][yy] = ans[x][y] + 1;
                        bfs.push({xx, yy});
                    }
                }
            }
        }
        
        return ans;
    }
};

// Using DP...
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = r ? mat[0].size() : 0;
        
        vector<vector<int>> ans(r, vector<int>(c, INT_MAX - 10000));
        
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                } else {
                    if(i > 0) ans[i][j] = min(ans[i][j], ans[i-1][j] + 1);
                    if(j > 0) ans[i][j] = min(ans[i][j], ans[i][j-1] + 1);
                }
            }
        }
        
        for(int i=r-1; i>=0; --i) {
            for(int j=c-1; j>=0; --j) {
                if(i < r-1) ans[i][j] = min(ans[i][j], ans[i+1][j] + 1);
                if(j < c-1) ans[i][j] = min(ans[i][j], ans[i][j+1] + 1);
            }
        }
        
        return ans;
    }
};
