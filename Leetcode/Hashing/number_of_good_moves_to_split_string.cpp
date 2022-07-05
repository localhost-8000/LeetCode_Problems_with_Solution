// Problem link:- https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
// Difficulty:- Medium


class Solution {
    bool haveUniqueCounts(vector<int>& left_cnt, vector<int>& right_cnt) {
        int l = 0, r = 0;
        
        for(int i=0; i<26; ++i) {
            l += left_cnt[i] ? 1 : 0;
            r += right_cnt[i] ? 1 : 0;
        }
        
        return l == r;
    }
    
public:
    int numSplits(string s) {
        int n = s.length();
        if(n <= 1) return 0;
        
        vector<int> left_cnt(26, 0), right_cnt(26, 0);
        
        for(auto ch : s) right_cnt[ch - 'a']++;
        
        int ans = 0;
        
        for(int i=0; i<n-1; ++i) {
            int ind = s[i] - 'a';
            
            left_cnt[ind]++;
            right_cnt[ind]--;
            
            if(haveUniqueCounts(left_cnt, right_cnt)) ans++;
        }
        
        return ans;
    }
};
