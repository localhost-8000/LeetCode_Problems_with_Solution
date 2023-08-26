// Problem link:- https://leetcode.com/problems/word-subsets/
// Difficulty:- Medium


// O(N + M)..
class Solution {
public:
    vector<int> countFrequency(string& word) {
        vector<int> freq(26, 0);
        
        for(char &ch : word) freq[ch - 'a']++;
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq_cnt(26, 0);
        
        for(string &word : words2) {
            vector<int> freq = countFrequency(word);
            for(int i=0; i<26; ++i) freq_cnt[i] = max(freq_cnt[i], freq[i]); 
        }
        
        vector<string> ans;
        
        for(string &word : words1) {
            vector<int> freq = countFrequency(word);
            int i = 0;
            
            for( ; i<26; ++i) {
                if(freq[i] < freq_cnt[i]) break;
            }
            
            if(i == 26) ans.push_back(word);
        }
        
        return ans;
    }
};
