// Problem link:- https://leetcode.com/problems/contiguous-array


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> umap;
        umap[0] = -1;
        int ans = 0;
        int cnt = 0;
        
        for(int i=0; i<n; ++i) {
            cnt += nums[i] == 1 ? 1 : -1;
            if(umap.find(cnt) != umap.end()) {
                int diff = i - umap[cnt];
                ans = max(ans, diff);
                continue;
            }
            
            umap[cnt] = i;
        }
        
        return ans;
    }
};
