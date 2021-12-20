// Problem link:- https://leetcode.com/problems/subsets-ii


class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>>& ans) {
        int n = arr.size();
       
        for(int i=0; i<n; ) {
            int cnt = 0;
            while(cnt + i < n && arr[i + cnt] == arr[i]) cnt++;
            
            int len = ans.size();
            for(int j=0; j<len; ++j) {
                vector<int> temp = ans[j];
                for(int k=0; k<cnt; ++k) {
                    temp.push_back(arr[i]);
                    ans.push_back(temp);
                }
            }
            
            i += cnt;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans = {{}};
        solve(nums, ans);
        
        return ans;
    }
};
