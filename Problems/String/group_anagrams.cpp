// Problem link:- https://leetcode.com/problems/group-anagrams

class Solution {
    int freq[26];
public:
    string bucketSort(string& str) {
        
        memset(freq, 0, sizeof(freq));
        
        for(const char &ch : str) freq[ch - 'a']++;
        
        string res = "";
        
        for(int i=0; i<26; ) {
            if(freq[i]) {
                res += (i + 'a');
                freq[i]--;
            }
            else i++;
        }
        
        return res;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;
        int n = strs.size();
        
        for(string &str : strs) {
            string temp = bucketSort(str);
            umap[temp].push_back(str);
        }
        
        for(auto [key, value] : umap) ans.push_back(value);
        
        return ans;
    }
};
