// Problem link:- https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Difficulty:- Medium

// Using sorting and two pointer.. O(NlogN)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        if(n <= 1) return 0;
        
        int l = 0, r = n - 1;
        int ans = 0;
        
        while(l + 1 <= r - 1) {
            ans += (nums[l+1] - nums[l]) * (l + 1);
            ans += (nums[r] - nums[r - 1]) * (n - r);
            l++, r--;
        }
        if(l < r) ans += (nums[l+1] - nums[l]) * (l + 1);
        
        return ans;
    }
};
