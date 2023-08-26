// Problem link:- https://leetcode.com/problems/smallest-string-with-swaps
// Difficulty:- Medium


class Solution {
    int char_track[26];
    vector<int> index_track;
public:
    void dfs(int s, vector<int> adj[], vector<int>& visited, string &str) {
        visited[s] = 1;
        index_track.push_back(s);
        char_track[str[s] - 'a']++;
        
        for(auto neigh : adj[s]) {
            if(!visited[neigh]) {
                dfs(neigh, adj, visited, str);
            }
        }
        
        return;
    }
    
    
    void sortString(string& s) {
        int p = 0;
        
        sort(index_track.begin(), index_track.end());
        
        for(int &index : index_track) {
            while(p < 26 && char_track[p] == 0) p++;
            s[index] = p + 'a';
            char_track[p]--;
        }
        
        return;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> adj[n];
        
        for(auto pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        
        vector<int> visited(n, 0);
        
        for(int i=0; i<n; ++i) {
            if(!visited[i]) {
                index_track.resize(0);
                memset(char_track, 0, sizeof(char_track));
                
                dfs(i, adj, visited, s);
                sortString(s);
            }
        }
        
        return s;
    }
};
