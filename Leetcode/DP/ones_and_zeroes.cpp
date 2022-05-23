// Problem link:- https://leetcode.com/problems/ones-and-zeroes/
// Difficulty:- Medium

class Solution {
    int dp[601][101][101];
public:
    pair<int, int> count0and1(string& str) {
        pair<int, int> res = {0, 0};
        for(char &bit : str) {
            (bit == '0') ? res.first++ : res.second++;
        }
        
        return res;
    }
    
    int helper(vector<pair<int, int>>& pair_cnt, int i, int zero_cnt, int one_cnt) {
        int n = pair_cnt.size();
        if(i == n || (zero_cnt == 0 and one_cnt == 0)) {
            return 0;
        }
        
        if(dp[i][zero_cnt][one_cnt] != -1) return dp[i][zero_cnt][one_cnt];
        
        if(pair_cnt[i].first > zero_cnt || pair_cnt[i].second > one_cnt) {
            return dp[i][zero_cnt][one_cnt] = helper(pair_cnt, i+1, zero_cnt, one_cnt);
        }
        
        int pick = 1 + helper(pair_cnt, i+1, zero_cnt - pair_cnt[i].first, one_cnt - pair_cnt[i].second);
        int dont_pick = helper(pair_cnt, i+1, zero_cnt, one_cnt);
        
        return dp[i][zero_cnt][one_cnt] = max(pick, dont_pick);
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>> pair_cnt;
        
        for(string& str : strs) {
            pair_cnt.push_back(count0and1(str));
        }
        
        return helper(pair_cnt, 0, m, n);
    }
};
