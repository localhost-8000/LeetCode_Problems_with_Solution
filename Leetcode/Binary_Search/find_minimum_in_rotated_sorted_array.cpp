// Problem link:- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1 || nums[0] < nums[n-1]) return nums[0];
        
        int left = 0, right = n - 1;
        int ans = -1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            int curr = nums[mid];
            if(curr > nums[mid+1]) {
                ans = nums[mid + 1];
                break;
            }
            
            if(curr >= nums[left]) {
                left = mid + 1;
            } else if(curr <= nums[right]) {
                right = mid - 1;
            }
        }
        return ans;
    }
};
