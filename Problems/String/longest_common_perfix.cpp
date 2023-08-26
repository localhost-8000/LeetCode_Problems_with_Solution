// Problem link: https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];
        for(int i=1; i<n; ++i) {
            string str = strs[i];
            int j = 0;
            while(j < str.length() && j < ans.length() && str[j] == ans[j]) {
                j++;
            }
            ans = ans.substr(0, j);
        }
        return ans;
    }
};
