// Problem link:- https://leetcode.com/problems/maximal-network-rank/
// Difficulty:- Medium

// O(N * N)... using degree count..
class Solution {
    int ans;
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int graph[n][n];
        int degree[n];
        
        memset(graph, 0, sizeof(graph));
        memset(degree, 0, sizeof(degree));
        
        for(auto road : roads) {
            int u = road[0], v = road[1];
            
            graph[u][v] = 1; graph[v][u] = 1;
            degree[u]++; degree[v]++;
        }
        
        ans = 0;
        
        for(int i=0; i<n-1; ++i) {
            for(int j=i+1; j<n; ++j) {
                ans = max(ans, degree[i] + degree[j] - graph[i][j]);
            }
        }
       
        return ans;
    }
};
