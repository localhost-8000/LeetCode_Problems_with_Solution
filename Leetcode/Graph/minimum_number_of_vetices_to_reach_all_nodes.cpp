// Problem link:- https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// Difficulty:- Medium

// Using in degree count.. O(n)
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> in_degree(n, false);
        
        for(auto edge : edges) in_degree[edge[1]] = true;
        
        vector<int> ans;
        for(int i=0; i<n; ++i) {
            if(in_degree[i] == false) ans.push_back(i);
        }
        
        return ans;
    }
};
