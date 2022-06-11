// Problem link:- https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Difficulty:- Medium

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        
        unordered_map<int, int> umap;
        for(int i=0; i<n && sum<=x; ++i) {
            umap[sum] = i;
            sum += nums[i];
        }
        umap[sum] = n;
        
        sum = 0;
        int res = INT_MAX;
        
        for(int i=n-1; i>=0 && sum <= x; --i) {
            auto itr = umap.find(x - sum);
            if(itr != umap.end() && i+1 >= itr->second) {
                res = min(res, n-i-1+itr->second);
            }
            sum += nums[i];
        }
        
        if(res == INT_MAX) return -1;
        
        return res;
    }
};

// Using subarray sum..
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // example 
        // [1,1,4,2,3] , x=5
        // target = sum(nums)-x, which is => 6 in this case 
        // we will try to find longest subarray with given target
        // max length with target is 3 [1,1,4]
        // our ans is nums.size()-3 => 2
        
        int target = -x;
        for(int num : nums) target += num;
        
        if(target < 0) return -1;
        
        int sum = 0, j = 0;
        int ans = INT_MIN;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            sum += nums[i]; 
            while(sum > target) {
                sum -= nums[j];
                j++;
            }
            if(sum == target) {
                ans = max(ans, i-j+1);
            }
        }
        
        return ans == INT_MIN ? -1 : n - ans;
    }
};
