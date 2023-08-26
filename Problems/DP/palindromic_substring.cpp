// Problem link:- https://leetcode.com/problems/palindromic-substrings
// Difficulty:- Medium

// DP approach.. O(n^2)
class Solution {
public:
    int isPalindrome(string& str, int left, int right, vector<vector<int>>& dp) {
        if(left >= right) return 1;
        if(dp[left][right] != -1) return dp[left][right];
        
        return dp[left][right] = str[left] == str[right] ? isPalindrome(str, left + 1, right - 1, dp) : 0;
    }
    
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int ans = 0;
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<=i; ++j) {
                ans += isPalindrome(s, j, i, dp);
            }
        }
        
        return ans;
    }
};
