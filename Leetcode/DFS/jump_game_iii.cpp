// Problem link:- 
// Difficulty:- Medium

class Solution {
    vector<int> dp;
public:
    bool canReachDestination(vector<int> graph[], vector<int>& arr, int s, vector<bool>& visited) {
        if(arr[s] == 0) return true;
        if(dp[s] != -1) return dp[s];
        if(visited[s]) return false;
        
        visited[s] = true;
        bool ans = false;
        
        for(auto neigh : graph[s]) {
            ans |= canReachDestination(graph, arr, neigh, visited);
        }
        
        return dp[s] = ans;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> graph[n];
        
        for(int i=0; i<n; ++i) {
            int left = i - arr[i];
            int right = i + arr[i];
            
            if(left >= 0) graph[i].push_back(left);
            if(right < n) graph[i].push_back(right);
        }
        
        dp.resize(n, -1);
        vector<bool> visited(n, false);
        
        return canReachDestination(graph, arr, start, visited);
    }
};
