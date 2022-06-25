// Problem link:- https://leetcode.com/problems/non-decreasing-array/
// Difficulty:- Medium

// O(N)..
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        bool flag = false;
        
        for(i = 0; i<n-1; ++i) {
            int curr = nums[i];
            int next = nums[i + 1];
            
            if(curr <= next) continue;
            if(flag) return false;
            
            int prev = i ? nums[i-1] : nums[i+1];
            int mx = max(prev, next);
            
            if(mx > next) nums[i+1] = nums[i];
            flag = true;
        }
        
        return true;
    }
};
