// first solution........

class Solution {
public:
    bool isMatch(string s, string p) {
        return regex_match(s, regex(p));
    }
};


// dp solution......

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
      
        // dp, where row represent pattern character and coloumn represent string character..
        int dp[m+1][n+1];
        
        // null strings are always equal.....
        dp[0][0] = 1;
        
        // null pattern can't match any string..except null
        for(int i=1; i<=n; ++i) {
            dp[0][i] = 0;
        }
        
        // check for pattern matches empty string or not...
        for(int i=1; i<=m; ++i) {
            if(p[i-1] != '*') {
                dp[i][0] = 0;
            }
            else {
                dp[i][0] = dp[i-2][0];
            }
        }
        
        // check for rest characters....
        for(int i=1; i<=m; ++i) {
            char pat = p[i-1];
            for(int j=1; j<=n; ++j) {
                char ch = s[j-1];
                if(pat == ch || pat == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pat == '*') {
                    if(dp[i-2][j] == 1) {
                        dp[i][j] = 1;
                    }
                    else if(ch == p[i-2] || p[i-2] == '.') {
                        dp[i][j] = dp[i][j-1];
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        
        // return if pattern matches string or not....
        return dp[m][n];
    }
};

// time complexity = O(N*N)
// space complexity = O(N*N)
