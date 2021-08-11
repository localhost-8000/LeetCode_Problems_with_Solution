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
            
            // current pattern character...index represent pattern string till now..
            char pat = p[i-1];
            
            for(int j=1; j<=n; ++j) {
                
                // current string character...index represent strnig till now
                char ch = s[j-1];
                
                // if current chars matches...check for previous one..
                if(pat == ch || pat == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                
                // if *...
                else if(pat == '*') {
                    // first check for two index above in pattern..like if "ab*" check if 'a' matches string
                    // it means making b* as null..
                    if(dp[i-2][j] == 1) {
                        dp[i][j] = 1;
                    }
                    
                    // if not above..check for one index above in pattern, '.' is also included..as it can also replace any character..
                    // ex. if pattern till now is ms* and string is msi, then "ms*" will become "mss*" and now check if 1st index i.e. 's'
                    // matches last index of till now string..i.e. 'i'
                    // if yes then check for if "ms*" matches "ms" ....
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
