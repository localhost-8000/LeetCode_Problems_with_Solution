// Problem link:- https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Difficulty:- Medium

// Simple approach using open and close variables...
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        string res = "";
        
        for(auto ch : s) {
            open += ch == '(' ? 1 : 0;
            close += ch == ')' ? 1 : 0;
            
            if(open >= close) {
                res += ch;
            } else {
                close--;
            }
        }
        
        int n = res.length();
        
        string ans = "";
        open = 0, close = 0;
        
        for(int i=n-1; i>=0; --i) {
            char ch = res[i];
            open += ch == '(' ? 1 : 0;
            close += ch == ')' ? 1 : 0;
            
            if(close >= open) {
                ans += ch;
            } else {
                open--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


// Using stack...
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        
        for(int i=0; i<n; ++i) {
            char curr = s[i];
            if(curr == '(') st.push(i);
            if(curr == ')') {
                if(st.empty()) s[i] = '*';
                else st.pop();
            }
        }
        
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        string ans = "";
        
        for(int i=0; i<n; ++i) {
            if(s[i] != '*') ans += s[i];
        }
        
        return ans;
    }
};
