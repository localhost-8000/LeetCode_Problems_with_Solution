// Problem link:- https://leetcode.com/problems/word-break

class Solution {
    unordered_set<string> us;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(const string &str : wordDict) us.insert(str);
        
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = i - 1; j >= 0; --j) {
                if(dp[j]) {
                    string word = s.substr(j, i - j);
                    if(us.find(word) != us.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};
