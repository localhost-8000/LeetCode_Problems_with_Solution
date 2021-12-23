// Problem link:- https://leetcode.com/problems/minimum-size-subarray-sum


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;
        
        int ans = INT_MAX;
        
        vector<int> pre_sum(n + 1, 0);
        for(int i = 1; i <= n; ++i) pre_sum[i] += pre_sum[i - 1] + nums[i - 1];
        
        for(int i = 1; i <= n; ++i) {
            int search_num = target + pre_sum[i - 1];
            
            auto itr = lower_bound(pre_sum.begin(), pre_sum.end(), search_num);
            if(itr != pre_sum.end()) 
                ans = min(ans, (int)(itr - (pre_sum.begin() + i - 1)));
        }
        
        if(ans == INT_MAX) return 0;
        return ans;
    }
};
