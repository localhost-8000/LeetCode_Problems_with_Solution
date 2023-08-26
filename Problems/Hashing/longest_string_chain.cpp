// Problem link:- https://leetcode.com/problems/longest-string-chain/
// Difficulty:- Medium


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_map<string, int> dp;
        int ans = 1;
        
        for(auto word : words) {
            int n = word.size();
            dp[word] = 1;
            
            for(int i=0; i<n; ++i) {
                string pred = word.substr(0, i) + word.substr(i+1);
                if(dp.find(pred) != dp.end()) {
                    dp[word] = max(dp[word], dp[pred] + 1);
                    ans = max(ans, dp[word]);
                }
            }
        }
        
        return ans;
    }
};
