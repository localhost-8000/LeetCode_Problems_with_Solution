// Problem link:- https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
// Difficulty:- Medium

class Solution {
public:
    void dfs(int u, int& ans, unordered_set<int> incoming_edges[], unordered_set<int> outgoing_edges[]) {
        
        // for edges incoming on u i.e. u <- v
        for(auto v : incoming_edges[u]) {
            outgoing_edges[v].erase(u);
            dfs(v, ans, incoming_edges, outgoing_edges);
        }
        
        // for edges going outward from u i.e. u -> v
        for(auto v : outgoing_edges[u]) {
            ans++;
            incoming_edges[v].erase(u);
            dfs(v, ans, incoming_edges, outgoing_edges);
        }
        
        return;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int> incoming_edges[n];
        unordered_set<int> outgoing_edges[n];
        
        int ans = 0;
        
        for(auto edge : connections) {
            // [x] <- [v1, v2, v3, ...]
            incoming_edges[edge[1]].insert(edge[0]);
            // [x] -> [v1, v2, v3, ...]
            outgoing_edges[edge[0]].insert(edge[1]);
        }
        
        dfs(0, ans, incoming_edges, outgoing_edges);
        
        return ans;
    }
};
