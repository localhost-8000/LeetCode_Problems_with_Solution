// Problem link:- https://leetcode.com/problems/sequential-digits

class Solution {
    vector<int> ans;
public:
    void dfs(int i, int num, int low, int high) {
        if(num >= low && num <= high) ans.push_back(num);
        
        if(num > high || i > 9) return;
        
        dfs(i + 1, num * 10 + i, low, high);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1; i<9; ++i) {
            dfs(i, 0, low, high);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
