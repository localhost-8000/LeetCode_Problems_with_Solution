// Problem link:- https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold
// Difficulty:- Medium


class Solution {
public:
    int divisonResult(vector<int>& nums, int div) {
        int cnt = 0;
        for(int &n : nums) {
            cnt += ceil(n / (double)div);
        }
        return cnt;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(divisonResult(nums, mid) <= threshold) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};
