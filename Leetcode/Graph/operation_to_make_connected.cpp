// Problem link:- https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Difficulty:- Medium

// Using BFS to count the no of components
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        
        vector<bool> visited(n, false);
        vector<int> adj[n];
        
        for(auto edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int comp = 0;
        
        for(int i=0; i<n; ++i) {
            if(visited[i]) continue;
            
            comp++;
            queue<int> q;
            q.push(i);
            
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                visited[curr] = true;
                
                for(int v : adj[curr]) {
                    if(!visited[v]) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
        
        return comp - 1;
    }
};
