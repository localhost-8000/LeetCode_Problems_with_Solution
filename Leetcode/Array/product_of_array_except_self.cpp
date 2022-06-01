// Problem link:- https://leetcode.com/problems/product-of-array-except-self/
// Difficulty:- Medium

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod = 1;
        int zero_cnt = 0;
        
        for(int num : nums) {
            if(num == 0) zero_cnt++;
            else prod *= num;
        }
        
        if(zero_cnt >= 2) prod = 0;
        
        for(int num : nums) {
            if(num == 0) ans.push_back(prod);
            else ans.push_back(zero_cnt >= 1 ? 0 : prod / num);
        }        
        
        return ans;
    }
};
