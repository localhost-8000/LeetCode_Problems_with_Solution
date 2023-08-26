// Problem link:- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Difficulty:- Medium

// basic stack approach using string
class Solution {
public:
    bool helper(string& str, char ch, int k) {
        int n = str.length();
        int cnt = 0;
        
        for(int i=n-1; i>=n-k; --i) {
            if(str[i] != ch) {
                break;
            }
            cnt++;
        }
        
        if(cnt != k) return false;
        
        for(int i=n-1; i>=n-k; --i) {
            str.pop_back();
        }
        
        return true;
    }
    
    string removeDuplicates(string s, int k) {
        string stack;
        vector<int> cnt(26, 0);
        
        for(char &c : s) {
            stack.push_back(c);
            cnt[c - 'a']++;
            
            if(cnt[c - 'a'] >= k) {
                bool removed = helper(stack, c, k);
                if(removed) cnt[c - 'a'] -= k;
            }
        }
        
        return stack;
    }
};

// Optimized stack approach
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        
        stack<pair<char, int>> st;
        st.push({s[0], 1});
        
        for(int i=1; i<n; ++i) {
            char c = s[i];
            
            if(st.empty()) {
                st.push({c, 1});
                continue;
            }
            
            if(st.top().first != c) {
                st.push({c, 1});
            } else if(st.top().second < k-1) {
                int freq = st.top().second;
                st.pop();
                st.push({c, freq + 1});
            } else {
                st.pop();
            }
        }
        
        string ans = "";
        
        while(!st.empty()) {
            pair<char, int> curr = st.top();
            st.pop();
            
            while(curr.second--) ans += curr.first;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
