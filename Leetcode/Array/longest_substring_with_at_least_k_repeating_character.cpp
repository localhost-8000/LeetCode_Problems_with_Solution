// Problem link:- https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// Difficulty:- Medium


class Solution {
    int cnt_store[26];
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        
        return solve(s, 0, n, k);
    }
    
    int solve(string& s, int start, int end, int k) {
        if(end < k) return 0;
        memset(cnt_store, 0, sizeof(cnt_store));
        
        for(int i=start; i<end; ++i) cnt_store[s[i] - 'a']++;
        
        int mid;
        
        for(int i=start; i<end; ++i) {
            if(cnt_store[s[i] - 'a'] >= k) continue;
            mid = i + 1;
            
            while(mid < end && cnt_store[s[mid] - 'a'] < k) mid++;
            
            return max(solve(s, start, i, k), solve(s, mid, end, k));
        }
        
        return end - start;
    }
};
