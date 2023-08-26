// Problem link:- https://leetcode.com/problems/top-k-frequent-elements/
// Difficulty:- Medium

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> umap;
        
        for(int &num : nums) umap[num]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto &mp : umap) {
            pq.push(make_pair(mp.second, mp.first));
        }
        
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
