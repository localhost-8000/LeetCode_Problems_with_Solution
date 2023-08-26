// Problem link:- https://leetcode.com/problems/n-queens-ii/
// Difficulty:- Medium

class Solution {
    unordered_set<int> row_visited;
    unordered_set<int> tb_visited;
    unordered_set<int> bt_visited;
 
public:
    int totalNQueens(int n, int curr = 0) {
        if(curr == n) return 1;
        
        int cnt = 0;
        
        for(int i=0; i<n; ++i) {
            if(row_visited.find(i) != row_visited.end() || tb_visited.find(i-curr) != tb_visited.end() || bt_visited.find(i+curr) != bt_visited.end()) continue;  
            
            row_visited.insert(i);
            tb_visited.insert(i-curr);
            bt_visited.insert(i+curr);
            
            cnt += totalNQueens(n, curr + 1);
            
            row_visited.erase(i);
            tb_visited.erase(i-curr);
            bt_visited.erase(i+curr);
        }
        
        return cnt;
    }
};
