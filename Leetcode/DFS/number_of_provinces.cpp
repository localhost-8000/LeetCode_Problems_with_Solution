// Problem link:- https://leetcode.com/problems/number-of-provinces/
// Difficulty:- Medium

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int ans = 0;
        
        bool visited[V];
        memset(visited, false, sizeof(visited));
        
        for(int i=0; i<V; ++i) {
            if(visited[i]) continue;
            
            ans++;
            stack<int> st;
            
            st.push(i);
            visited[i] = true;
            
            while(!st.empty()) {
                int node = st.top();
                st.pop();
                
                for(int neigh = 0; neigh < V; neigh++) {
                    if(!visited[neigh] && isConnected[node][neigh]) {
                        visited[neigh] = true;
                        st.push(neigh);
                    }
                }
            }
        }
        
        return ans;
    }
};
