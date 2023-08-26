// Problem link:- https://leetcode.com/problems/lexicographical-numbers


class Solution {
    vector<int> ans;
public:
    void solve(int i, int n) {
        if(i > n) return;
        
        ans.push_back(i);
        solve(i * 10, n);
        
        if(i % 10 != 9) solve(i + 1, n);
    }
    
    vector<int> lexicalOrder(int n) {
        solve(1, n);
        return ans;
    }
};
