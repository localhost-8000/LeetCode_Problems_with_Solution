// Problem link:- https://leetcode.com/problems/n-queens/
// Difficulty:- Hard

// Backtracking
class Solution {
    vector<vector<string>> ans;
    vector<bool> row_visited;
    unordered_set<int> tb;
    unordered_set<int> tu;
    
public:
    void backtrack(int n, int curr, vector<string>& strs) {
        if(curr == n) {
            ans.push_back(strs);
            return;
        }
        
        string s = "";
        for(int i=0; i<n; ++i) {
            s += '.';
        }
        
        for(int i=0; i<n; ++i) {
            if(row_visited[i] == true || tb.find(i + curr) != tb.end() || tu.find(i - curr) != tu.end()) {
                continue;
            }
            
            row_visited[i] = true;
            tb.insert(i+curr);
            tu.insert(i-curr);
            
            s[i] = 'Q';
            strs.push_back(s);
            
            backtrack(n, curr + 1, strs);
            
            row_visited[i] = false;
            tb.erase(i+curr);
            tu.erase(i-curr);
            
            strs.pop_back();
            s[i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        row_visited.resize(n, false);
        vector<string> strs;
        
        backtrack(n, 0, strs);
        
        return ans;
    }
};
