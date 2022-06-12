// Problem link:- https://leetcode.com/problems/maximum-erasure-value/
// Difficulty:- Medium

// Using prefix_sum and map...
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_sum(n);
        pre_sum[0] = nums[0];
        
        for(int i=1; i<n; ++i) pre_sum[i] += nums[i] + pre_sum[i-1];
        
        int pre_index = -1;
        int curr_sum = 0, res = 0;
        unordered_map<int, int> umap;
        
        for(int i=0; i<n; ++i) {
            int num = nums[i];
            auto itr = umap.find(num);
            
            if(itr == umap.end() || itr->second < pre_index) {
                curr_sum += num;
                umap[num] = i;
            } else if(itr->second > pre_index) {
                res = max(res, curr_sum);
                curr_sum = pre_sum[i] - pre_sum[itr->second];
                
                pre_index = itr->second;
                umap[num] = i;
            }
        }
        
        res = max(res, curr_sum);
        
        return res;
    }
};

// Using sliding window with set...
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0, curr = 0;
        int left = 0;
        
        unordered_set<int> visited;
        
        for(int i=0; i<n; ++i) {
            int num = nums[i];
            
            while(visited.find(num) != visited.end()) {
                visited.erase(nums[left]);
                curr -= nums[left++];
            }
            
            curr += num;
            res = max(res, curr);
            visited.insert(num);
        }
        
        return res;
    }
};
