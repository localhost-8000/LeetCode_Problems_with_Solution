// Problem link:- https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Difficulty:- Medium

class Solution {
public:
    int recurse(vector<int> adj[], int head, vector<int>& informTime) {
        int n = adj[head].size();
        
        if(adj[head].size() == 0) return 0;
        
        int curr_time = 0;
        
        for(int neigh : adj[head]) {
            int res = recurse(adj, neigh, informTime);
            curr_time = max(curr_time, res);
        }
        
        return curr_time + informTime[head]; 
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        int head;
        
        for(int i=0; i<n; ++i) {
            if(manager[i] == -1) head = i;
            else adj[manager[i]].push_back(i);
        }
        
        return recurse(adj, head, informTime);
    }
};
