// Problem Link:- https://leetcode.com/problems/maximum-number-of-removable-characters
// Difficulty:- Medium


class Solution {
public:
    bool canBeSubsequence(string s, string& p, vector<int>& removable, int k) {
        int l1 = s.length();
        int l2 = p.length();
        
        for(int i=0; i<k; ++i) {
            int index = removable[i];
            s[index] = '*';
        }
        
        int i = 0, j = 0;
        while(i < l1 && j < l2) {
            if(s[i] == p[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        
        if(j == l2) return true;
        return false;
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size();
        int ans;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(canBeSubsequence(s, p, removable, mid)) {
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        
        return ans;
    }
};
