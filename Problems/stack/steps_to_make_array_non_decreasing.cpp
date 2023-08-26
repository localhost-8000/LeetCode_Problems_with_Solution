// Problem link:- https://leetcode.com/problems/steps-to-make-array-non-decreasing/
// Difficulty:- Medium

// stack + dp.. O(n)
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> stack, dp(n, 0);
        int ans = 0;
        
        for(int i=n-1; i>=0; --i) {
            while(!stack.empty() && nums[i] > nums[stack.back()]) {
                dp[i] = max(++dp[i], dp[stack.back()]);
                stack.pop_back();
                ans = max(ans, dp[i]);
            }
            stack.push_back(i);
            
        }
        
        return ans;
    }
};
