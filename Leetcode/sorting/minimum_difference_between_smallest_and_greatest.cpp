// Problem link:- https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
// Difficulty:- Medium

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0; 
        
        sort(begin(nums), end(nums));
        int ans = INT_MAX, j=3;
        
        for(int i=n-1; i>=n-4; --i) {
            int curr = nums[i] - nums[j--];
            ans = min(ans, curr);
        }
        
        return ans;
    }
};
