// Problem link:- 
// Difficulty:- Medium

// basic approach using unordered map.. O(n * 2^k)
class Solution {
public:
    void generateSubsequence(string str, int i, string s, unordered_map<string, int>& umap) {
        int n = str.length();
        
        if(i == n) {
            umap[s]++;
            return;
        }
        
        generateSubsequence(str, i+1, s+str[i], umap);
        generateSubsequence(str, i+1, s, umap);
        
        return;
    }
    
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> umap;
        
        for(string str : strs) {
            generateSubsequence(str, 0, "", umap);
        }
        
        int cnt = -1;
        
        for(auto pair : umap) {
            if(pair.second == 1) cnt = max(cnt, (int)size(pair.first));
        }
        
        return cnt;
    }
};

// O(n^2 * k)
class Solution {
public:
    bool isSubsequence(string str, string s) {
        int n1 = str.length();
        int n2 = s.length();
        
        if(n1 < n2) return false;
        
        int i = 0, j = 0;
        
        while(i < n1 && j < n2) {
            if(str[i] == s[j]) {
                j++;
            }
            i++;
        }
        
        return j == n2;
    }
    
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        
        int ans = -1;
        
        for(int i=0; i<n; ++i) {
            int j = 0;
            for(; j<n; ++j) {
                if(i == j) continue;
                if(isSubsequence(strs[j], strs[i])) break;
            }
            
            if(j == n) ans = max(ans, (int)strs[i].size());
        }
        
        return ans;
    }
};
