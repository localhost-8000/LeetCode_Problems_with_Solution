// Problem link:- https://leetcode.com/problems/min-cost-to-connect-all-points
// Difficulty:- Medium


// Prims Algorithm..
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        vector<bool> visited(n, false);
        min_heap.push({0, 0});
        int ans = 0;
        
        int i = 0;
        
        while(i < n) {
            pair<int, int> curr_elem = min_heap.top();
            min_heap.pop();
            
            int w = curr_elem.first;
            int node = curr_elem.second;
            
            if(visited[node]) continue;
            
            visited[node] = true;
            ans += w;
            i++;
            
            for(int j=0; j<n; ++j) {
                if(visited[j]) continue;
                
                int curr_w = abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]);
                min_heap.push({curr_w, j});
            }
        }
        
        return ans;
    }
};


// Optimized Prism algorithm...
class Solution {
public:
    int getLeastWeight(vector<int>& dist, vector<bool>& visited) {
        int n = dist.size();
        
        int min = INT_MAX, min_i;
        
        for(int i=0; i<n; ++i) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                min_i = i;
            }
        }
        
        return min_i;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        
        dist[0] = 0;
        int ans = 0;
        int i = 0;
        
        while(i < n) {
            int node = getLeastWeight(dist, visited);
            
            visited[node] = true;
            ans += dist[node];
            i++;
            
            for(int j=0; j<n; ++j) {
                
                int curr_w = abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]);
                
                if(!visited[j] && dist[j] > curr_w) dist[j] = curr_w;
                
            }
        }
        
        return ans;
    }
};
