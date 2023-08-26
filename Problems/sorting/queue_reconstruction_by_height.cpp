// Problem link:- https://leetcode.com/problems/queue-reconstruction-by-height/
// Difficulty:- Medium

// O(N * N)...
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(begin(people), end(people), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        vector<vector<int>> ans;
        
        for(auto arr : people) {
            int pos = arr[1];
            ans.insert(begin(ans) + pos, arr);
        }
        
        return ans;
    }
};
