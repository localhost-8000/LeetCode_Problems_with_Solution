// Problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        
        unordered_map<char, int> umap;
        int ans = 0;
        int cnt = 0;
        int prev_index = -1;
        
        for(int i=0; i<n; ++i) {
            if(umap.find(s[i]) != umap.end() && umap[s[i]] > prev_index) {
                ans = max(ans, cnt);
                cnt = i - umap[s[i]];
                prev_index = umap[s[i]];
            } else {
                cnt++;
            }
            umap[s[i]] = i;
        }
        ans = max(ans, cnt);
        
        return ans;
    }
};
