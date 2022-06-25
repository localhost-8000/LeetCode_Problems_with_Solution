// Problem link:- https://leetcode.com/problems/non-decreasing-array/
// Difficulty:- Medium


// For i=0 to i<n-1, whenever we encounter the first invalid element i.e. arr[i] > arr[i+1], we have two choice
// 1. decrease arr[i]
// 2. increase arr[i+1]

// To decrease the current element it must be substituted with x such that arr[i-1] <= x <= arr[i+1] ..... for i >= 0,
// so calculate max(arr[i-1], arr[i+1]) and if it is not less or equal to arr[i+1] then we can't decrease the current element.

// So we have the increase the next element i.e. arr[i+1] and the optimal case would be just make arr[i+1] = arr[i];
// Flag variable is used to check that operation is performed at most once.
    
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
