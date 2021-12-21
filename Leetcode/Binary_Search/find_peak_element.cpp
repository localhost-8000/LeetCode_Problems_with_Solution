// Problem link:- 

// linear approach...
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 0;
        
        for(int i=1; i<n-1; i++) {
            int curr = nums[i];
            int prev = nums[i - 1];
            int next = nums[i + 1];
            if(curr > prev && curr > next) return i;
        }
        
        if(nums[0] > nums[1]) return 0;
        return n-1;
    }
};


// Optimized approach..O(logN)..
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            int curr = nums[mid];
            int next = nums[mid + 1];
            
            if(curr > next) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};
