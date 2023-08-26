// Problem link: https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        
        for(int i=0; i<nums.size(); ++i) {
            int curr = nums[i];
            int n = ans.size();
            for(int j=0; j<n; ++j) {
                vector<int> temp = ans[j];
                temp.push_back(curr);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
