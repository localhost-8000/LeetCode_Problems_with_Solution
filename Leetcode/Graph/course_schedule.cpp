// Problem link: https://www.geeksforgeeks.org/graph-and-its-representations/

class Solution {
public:
    
    bool detectCycleByDFS(vector<int> adj[], int V, vector<bool>& vis, int s, vector<bool>& recSt) {
        vis[s] = true;
        recSt[s] = true;
        
        for(auto v : adj[s]) {
            if(!vis[v] && detectCycleByDFS(adj, V, vis, v, recSt)) {
                return true;
            }
            else if(recSt[v] == true) {
                return true;
            }
        }
        
        recSt[s] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(int i=0; i<prerequisites.size(); ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> vis(numCourses, false);
        vector<bool> recSt(numCourses, false);
        
        for(int i=0; i<numCourses; ++i) {
            if(!vis[i]) {
                if(detectCycleByDFS(adj, numCourses, vis, i, recSt)) {
                    return false;
                }
            }
        }
        return true;
    }
};
