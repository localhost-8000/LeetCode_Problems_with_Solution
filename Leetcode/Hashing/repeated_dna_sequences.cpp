// Problem link:- https://leetcode.com/problems/repeated-dna-sequences/
// Difficulty:- Medium


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        
        if(n <= 10) return ans;
        
        unordered_map<string, int> umap;
        
        umap[s.substr(0, 10)]++;
        
        for(int i=10; i<n; ++i) {
            umap[s.substr(i - 9, 10)]++;
        }
        
        for(auto pair : umap) {
            if(pair.second > 1) ans.push_back(pair.first);
        }
        
        return ans;
    }
};


// solution can be further optimized using custom hash function..
