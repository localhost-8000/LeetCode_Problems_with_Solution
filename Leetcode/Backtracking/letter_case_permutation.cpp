// Problem link:- https://leetcode.com/problems/letter-case-permutation
// Difficulty level:- Medium


class Solution {
    vector<string> ans;
public:
    void backtrack(string& str, int i, string s) {
        int n = str.length();
        if(i >= n) {
            ans.push_back(s);
            return;
        }
        
        if(isalpha(str[i])) {
            char temp, ch = str[i];
            if(isupper(ch)) temp = tolower(ch);
            else temp = toupper(ch);
            
            backtrack(str, i + 1, s + temp);
        }
        
        backtrack(str, i + 1, s + str[i]);
    }
    
    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0, "");
        
        return ans;
    }
};
