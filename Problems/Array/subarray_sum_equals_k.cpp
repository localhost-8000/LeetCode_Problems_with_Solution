// Problem link:- https://leetcode.com/problems/subarray-sum-equals-k
// Difficulty:- Medium

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int ans = 0;
        int sum = 0;
        
        for(int& num : nums) {
            sum += num;
            if(sum == k) ans++;
            if(umap.find(sum - k) != umap.end()) ans += umap[sum - k];
            
            umap[sum]++;
        }
        
        return ans;
    }
};
