// Problem link:- https://leetcode.com/problems/palindrome-partitioning

// dfs search..brute force method..
class Solution {
    vector<vector<string>> ans;
public:
    bool isPalindrome(string &str, int l, int r) {
        while(l < r) {
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    void dfs(string& str, int start, vector<string>& curr) {
        int n = str.length();
        if(start >= n) {
            ans.push_back(curr);
            return;
        }
        
        for(int i = start; i < n; ++i) {
            if(isPalindrome(str, start, i)) {
                curr.push_back(str.substr(start, i - start + 1));
                dfs(str, i + 1, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(s, 0, curr);
        
        return ans;
    }
};


// futrther optimized..with dp
class Solution {
    vector<vector<string>> ans;
public:
    bool isPalindrome(string &str, int l, int r) {
        while(l < r) {
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    void dfs(string& str, int start, vector<string>& curr, vector<vector<bool>>& dp) {
        int n = str.length();
        if(start >= n) {
            ans.push_back(curr);
            return;
        }
        
        for(int i = start; i < n; ++i) {
            if(str[start] == str[i] && (i - start <= 2 || dp[start + 1][i - 1])) {
                dp[start][i] = true;
                curr.push_back(str.substr(start, i - start + 1));
                dfs(str, i + 1, curr, dp);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        vector<string> curr;
        dfs(s, 0, curr, dp);
        
        return ans;
    }
};
