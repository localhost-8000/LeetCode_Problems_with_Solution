// Problem link:- https://leetcode.com/problems/find-eventual-safe-states/
// Difficulty:- Medium


class Solution {
    vector<bool> terminal, visited;
public:
    bool safeNode(vector<vector<int>>& graph, int s) {
        if(terminal[s]) return true;
        if(visited[s]) return false;
        
        int n = graph[s].size();
        if(n == 0) {
            terminal[s] = true;
            return true;
        }
        
        visited[s] = true;
        bool ans = true;
        
        for(int u=0; u<n; ++u) {
            int neigh = graph[s][u];
            if(s == neigh) {
                ans = false;
                break;
            }
            
            ans = ans & safeNode(graph, neigh);
        }
        
        return terminal[s] = ans;   
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> ans;
        
        terminal.resize(V, false);
        
        for(int v=0; v<V; ++v) {
            visited.resize(V, false);
            if(safeNode(graph, v)) ans.push_back(v);
        }
        
        return ans;
    }
};
