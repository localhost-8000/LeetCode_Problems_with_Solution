class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        
        // create dp having row as start index and coloumn as last index of substring..
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        // initialize dp for length 1 substring.........
        for(int i=0; i<n; ++i) {
            dp[i][i] = 1;
        }
        // initialize dp for length 2 substring......
        for(int i=0; i<n-1; ++i) {
            dp[i][i+1] = (s[i] == s[i+1]) ? 1 : 0;
        }
        
        // if leftMost and Rightmost elements are equal and middle elemnts are 
        // palindrome, then current substring is palindrome.....
        for(int len = 3; len <= n; ++len) {
            for(int start = 0; start + len - 1 < n; ++start) {
                int left_i = start;
                int right_i = start + len - 1;
                if(s[left_i] == s[right_i] && dp[left_i + 1][right_i - 1] == 1) {
                    dp[left_i][right_i] = 1;
                }
            }
        }
        
        // check for longest substring....
        int max_len = 0; 
        int start_index = 0;
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                // cout<<dp[i][j]<<" ";
                if(j - i + 1 > max_len && dp[i][j] == 1) {
                    max_len = j - i + 1;
                    start_index = i;
                }
            }
            // cout<<endl;
        }
        
        string ans = s.substr(start_index, max_len);
        return ans;
        
    }
};

// time complexity is O(N*N)...
// space complexity is O(N*N)...
