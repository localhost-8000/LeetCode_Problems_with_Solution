// Problem link:- https://leetcode.com/problems/sort-colors


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while(left < n && nums[left] == 0) left++;
        while(right >= 0 && nums[right] == 2) right--;
        
        int i = left;
        
        while(left < right && i <= right) {
            
            int curr = nums[i];
            
            if(curr == 0) swap(nums[left++], nums[i++]);
            
            else if(curr == 2) swap(nums[right--], nums[i]);
            
            else i++;
        }
        
    }
};
