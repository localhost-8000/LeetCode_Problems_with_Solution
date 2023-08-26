// Problem link:- https://leetcode.com/problems/keys-and-rooms/
// Difficulty:- Medium

class Solution {
public:
    void dfs(vector<int> adj[], int u, vector<bool>& visited) {
        if(visited[u]) return;
        
        visited[u] = true;
        
        for(int neigh : adj[u]) {
            if(!visited[neigh]) dfs(adj, neigh, visited);
        }
        
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> adj[n];
        
        for(int i=0; i<n; ++i) {
            int l = rooms[i].size();
            for(int j=0; j<l; ++j) adj[i].push_back(rooms[i][j]);
        }
        
        vector<bool> visited(n, false);
        dfs(adj, 0, visited);
        
        for(auto flag : visited) {
            if(!flag) return false;
        }
        
        return true;
    }
};

// Much cleaner code..
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        
        stack<int> st;
        st.push(0);
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            for(int neigh : rooms[node]) {
                if(!visited[neigh]) {
                    visited[neigh] = true;
                    st.push(neigh);
                }
            }
        }
        
        for(auto flag : visited) {
            if(!flag) return false;
        }
        
        return true;
    }
};
