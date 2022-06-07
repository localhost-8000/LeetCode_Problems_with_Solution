// Problem link:- https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
// Difficulty:- Medium

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = r ? maze[0].size() : 0;
        
        vector<vector<int>> arr(r, vector<int>(c, 100000));
        
        int isEntrance = 0;
        queue<pair<int, int>> bfs;
        
        int ent_x = entrance[0], ent_y = entrance[1];
        maze[ent_x][ent_y] = '#';
        
        bfs.push({ent_x, ent_y});
        arr[ent_x][ent_y] = 0;
        
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = INT_MAX;
        
        while(!bfs.empty()) {
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();
            
            if(maze[x][y] == '+' || (maze[x][y] == '#' && isEntrance++)) continue;
            
            for(int i=0; i<4; ++i) {
                int xx = dirs[i][0] + x;
                int yy = dirs[i][1] + y;

                if(xx >= 0 && yy >= 0 && xx < r && yy < c) {
                    char curr = maze[xx][yy];
                    if(curr == '+' || curr == '#') continue;
                    if(arr[xx][yy] > 1 + arr[x][y]) {
                        arr[xx][yy] = 1 + arr[x][y];
                        bfs.push({xx, yy});
                    }
                    if(xx == 0 || xx == r-1 || yy == 0 || yy == c-1) {
                        ans = min(ans, arr[xx][yy]);
                    }
                }
            }
        }
        
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};


// Cleaner code...
int dir[5] = {0, -1, 0, 1, 0};

class Solution {
public:
    int nearestExit(vector<vector<char>>& m, vector<int>& ent) {
        queue<array<int, 3>> q; // i, j, steps
        q.push({ent[0], ent[1], 0});
        while(!q.empty()) {
            auto [i, j, steps] = q.front(); q.pop();
            if ((i != ent[0] || j != ent[1]) && (i == 0 || j == 0 || i == m.size() - 1 || j == m[i].size() - 1))
                return steps;
            for (int d = 0; d < 4; ++d) {
                int di = i + dir[d], dj = j + dir[d + 1];
                if (di >= 0 && dj >= 0 && di < m.size() && dj < m[di].size() && m[di][dj] == '.') {
                    m[di][dj] = '+';
                    q.push({di, dj, steps + 1});
                }
            }
        }
        return -1;
    }
};
