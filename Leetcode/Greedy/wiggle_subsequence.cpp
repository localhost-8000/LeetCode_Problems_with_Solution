// Problem link:- https://leetcode.com/problems/wiggle-subsequence

// Brute and dp approach:- 

// Greedy approach..
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        int prev_diff = nums[1] - nums[0];
        int ans_cnt = prev_diff != 0 ? 2 : 1;
        
        for(int i=2; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            if((diff < 0 && prev_diff >= 0) || (diff > 0 && prev_diff <= 0)) {
                ans_cnt++;
                prev_diff = diff;
            }
        }
        return ans_cnt;
    }
};
