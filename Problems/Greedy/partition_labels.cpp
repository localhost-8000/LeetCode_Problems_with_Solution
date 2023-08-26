// Problem link:- https://leetcode.com/problems/partition-labels/
// Difficulty:- Medium


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> last_occur(26, 0);
        
        for(int i=0; i<n; ++i) {
            last_occur[s[i] - 'a'] = i;
        }
        
        int start = 0, end = 0;
        vector<int> ans;
        
        for(int i=0; i<n; ++i) {
            end = max(end, last_occur[s[i] - 'a']);
            if(i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};
