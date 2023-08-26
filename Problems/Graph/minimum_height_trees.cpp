// Problem link:- https://leetcode.com/problems/minimum-height-trees/

// naive approach..give TLE... TC:- O(n*n)
class Solution {
public:
    void createGraph(int n, vector<vector<int>>& edges, vector<int> adj[]) {
        for(int i=0; i<n-1; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    int findHeight(int root, int n, vector<int> adj[]) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        
        int ans = 0;
        
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                int u = q.front();
                visited[u] = true;
                q.pop();
                for(const int &v : adj[u]) {
                    if(!visited[v]) q.push(v);
                }
            }
            ans += !q.empty() ? 1 : 0;
        }
        return ans;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n == 0) return ans;
        
        vector<int> adj[n];
        createGraph(n, edges, adj);
        
        vector<pair<int, int>> temp;

        for(int i=0; i<n; ++i) {
            int curr_height = findHeight(i, n, adj);
            temp.push_back(make_pair(curr_height, i));
        }
        
        sort(temp.begin(), temp.end());
        ans.push_back(temp[0].second);
        for(int i=1; i<n; ++i) {
            if(temp[i].first == temp[i-1].first) {
                ans.push_back(temp[i].second);
            } else {
                break;
            }
        }
        
        return ans;
    }
};

// efficient method using mathod of topological sort..TC:- O(N)
class Solution {
public:
    void createGraph(int n, vector<vector<int>>& edges, unordered_set<int> adj[]) {
        for(int i=0; i<n-1; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
    }
    
    vector<int> removeLeavesAndFindNewLeaves(unordered_set<int> adj[], vector<int>& leaves) {
        vector<int> new_leaves;
        
        for(const int &leaf : leaves) {
            // neighbour of the leaf node
            int leaf_neigh = *(adj[leaf].begin());
            
            // remove leaf node from its neighbour...
            adj[leaf_neigh].erase(leaf);
            
            // if leaf node...push..
            if(adj[leaf_neigh].size() == 1) new_leaves.push_back(leaf_neigh);
        }
        
        return new_leaves;
    }
    
    vector<int> findAllLeavesNodes(unordered_set<int> adj[], int n) {
        vector<int> leaves;
        for(int i=0; i<n; ++i) {
            if(adj[i].size() == 1) leaves.push_back(i);
        }
        return leaves;
    }
    
    // minimum height of the tree will be achieved when root is centroid...and a tree can have max of two centroids..
    // make a layer of leaf nodes and layer by layer remove then until we get only two nodes.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n < 2) {
            vector<int> ans;
            for(int i=0; i<n; ++i) ans.push_back(i);
            return ans;
        }
        
        // create the adjacency list graph...
        unordered_set<int> adj[n];
        createGraph(n, edges, adj);
        
        // get leaves nodes...
        vector<int> leaves = findAllLeavesNodes(adj, n);
        
        int rem_nodes = n;
        
        while(rem_nodes > 2) {
            
            rem_nodes -= leaves.size();
            
            leaves = removeLeavesAndFindNewLeaves(adj, leaves);
        }
        
        return leaves;
    }
};
