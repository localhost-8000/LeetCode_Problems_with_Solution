// Problem link:- https://leetcode.com/problems/maximum-total-importance-of-roads/
// Difficulty:- Medium

// O(N + NlogN)...
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> node_cnt(n, 0);
        
        for(auto road : roads) {
            node_cnt[road[0]]++;
            node_cnt[road[1]]++;
        }
        
        sort(node_cnt.begin(), node_cnt.end());
        long long ans = 0;
        
        for(int i=0; i<n; ++i) {
            ans += node_cnt[i] * (i + 1);
        }
        
        return ans;
    }
};
