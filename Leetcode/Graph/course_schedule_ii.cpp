// Problem link:- https://leetcode.com/problems/course-schedule-ii


class Solution {
public:
    bool dfs(vector<int> adj[], int s, bool visited[], bool recursionStack[], stack<int>& st) {
        visited[s] = true;
        recursionStack[s] = true;
        
        for(const int& v : adj[s]) {
            if(!visited[v] && !dfs(adj, v, visited, recursionStack, st)) {
                return false;
            }
            else if(recursionStack[v] == true) {
                return false;
            }
        }
        st.push(s);
        recursionStack[s] = false;
        
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> adj[numCourses];
        
        // create adjacency list...
        for(const auto &arr : prerequisites) {
            int u = arr[1];
            int v = arr[0];
            adj[u].push_back(v);
        }
        
        bool visited[numCourses];
        memset(visited, false, sizeof(visited));
        bool recursionStack[numCourses];
        memset(recursionStack, false, sizeof(recursionStack));
        
        vector<int> ans;
        stack<int> st;
        
        for(int i=0; i<numCourses; ++i) {
            if(!visited[i]) {
                bool result = dfs(adj, i, visited, recursionStack, st);
                
                if(!result) return ans;
            }
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};

// by counting indegrees approach...
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> adj[numCourses];
        
        int indegree[numCourses];
        memset(indegree, 0, sizeof(indegree));
        
        // create adjacency list...
        for(const auto &arr : prerequisites) {
            int u = arr[1];
            int v = arr[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        vector<int> ans;
        queue<int> Q;
        
        for(int i=0; i<numCourses; ++i) {
            if(indegree[i] == 0) Q.push(i);
        }
        
        while(!Q.empty()) {
            int curr_node = Q.front();
            Q.pop();
            ans.push_back(curr_node);
            
            for(int &neighbour : adj[curr_node]) {
                indegree[neighbour]--;
                
                if(indegree[neighbour] == 0) Q.push(neighbour);
            }
        }
        
        if(ans.size() == numCourses) return ans;
        ans.clear();
        return ans;
        
    }
};
