// Problem link:- https://leetcode.com/problems/distinct-subsequences/
// Difficulty:- Hard


class Solution {
    vector<vector<int>> dp;
    int n, m;
public:
    int solve(string& s, string& t, int i, int j) {
        if(j == m) return 1;
        if(i == n || n - i < m - j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int pick = s[i] == t[j] ? solve(s, t, i+1, j+1) : 0;
        int no_pick = solve(s, t, i+1, j);
        
        return dp[i][j] = pick + no_pick;
    }
    
    int numDistinct(string s, string t) {
        n = s.length(), m = t.length();
        dp.resize(n, vector<int>(m, -1));
        
        return solve(s, t, 0, 0);
    }
};
