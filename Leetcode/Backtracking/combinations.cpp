// Problem link:- https://leetcode.com/problems/combinations/
// Difficulty:- Medium


class Solution {
    vector<vector<int>> ans;
public:
    void backtrack(int n, int k, int idx, vector<int>& temp) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if(idx > n) return;
        
        
        for(int i=idx; i<=n; ++i) {
            temp.push_back(i);
            backtrack(n, k, i + 1, temp);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        
        backtrack(n, k, 1, temp);
        
        return ans;
    }
};
