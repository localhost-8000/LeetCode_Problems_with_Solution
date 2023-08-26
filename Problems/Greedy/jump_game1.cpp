// Problem link: https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int range = 0;
        
        for(int i=0; i<n-1; ++i) {
            
            if(i > range && i != 0) break;
            
            int curr = nums[i] + i;
            range = max(curr, range);
        }
        
        if(range >= n - 1) return true;
        return false;

    }
};
