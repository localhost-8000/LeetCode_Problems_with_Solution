// Problem link:- https://leetcode.com/problems/find-and-replace-pattern/
// Difficulty:- Medium

// O(n * k)
class Solution {
    unordered_map<char, char> char_cnt;
    
    string generateEquivalentString(const string& str) {
        char_cnt.clear();
        
        string result = "";
        char ch = 'a';
        
        for(char c : str) {
            auto itr = char_cnt.find(c);
            if(itr == end(char_cnt)) char_cnt[c] = ch++;
            
            result += char_cnt[c];
        }
        
        return result;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string patt = generateEquivalentString(pattern);
        
        for(auto word : words) {
            string converted_word = generateEquivalentString(word);
            if(patt == converted_word) ans.push_back(word);
        }
        
        return ans;
    }
};
