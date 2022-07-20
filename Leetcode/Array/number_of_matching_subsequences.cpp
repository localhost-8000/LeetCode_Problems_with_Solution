// Problem link:- https://leetcode.com/problems/number-of-matching-subsequences/
// Difficulty:- Medium

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, string>>> waiting(26);
        for(string& word : words) waiting[word[0] - 'a'].push_back({0, word});
        
        int ans = 0;
        
        for(char& ch : s) {
            auto curr = waiting[ch - 'a'];
            waiting[ch - 'a'].clear();
            
            for(auto pair : curr) {
                pair.first++;
                string word = pair.second;
                
                if(pair.first == word.length()) ans++;
                else waiting[word[pair.first] - 'a'].push_back({pair.first, word});
            }
        }
        
        return ans;
    }
};
