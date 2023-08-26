// Problem link:- https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
// Difficulty:- Medium


class Solution {
public:
    bool isPossible(vector<int>& nums, int maxO, int penalty) {
        int cnt = 0;
        for(int &x : nums) {
            int rem = (x - 1) / penalty;
            cnt += rem;
        }
        
        return cnt <= maxO;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(isPossible(nums, maxOperations, mid)) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};
