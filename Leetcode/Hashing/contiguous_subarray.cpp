// Problem link:- https://leetcode.com/problems/contiguous-array


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        for(int &num : nums) {
            num = num == 0 ? -1 : num;
        }
        
        unordered_map<int, int> umap;
        umap[nums[0]] = 0;
        umap[0] = -1;
        int ans = 0;
        
        for(int i=1; i<n; ++i) {
            nums[i] += nums[i - 1];
            int curr = nums[i];
            
            if(curr == 0) {
                
            }
            if(umap.find(curr) != umap.end()) {
                int diff = i - umap[curr];
                ans = max(ans, diff);
                continue;
            }
            
            umap[curr] = i;
        }
        
        return ans;
    }
};
