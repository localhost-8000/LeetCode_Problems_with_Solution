// problem link:- https://leetcode.com/problems/is-subsequence/

// recursive approach
class Solution {
public:
    bool check(string s, string t, int i, int j) {
        if(i < 0) {
            return true;
        }
        if(j < 0) {
            return false;
        }
        if(s[i] == t[j]) {
            return check(s, t, i-1, j-1);
        }
        return check(s, t, i, j-1);
    }
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) {
            return true;
        }
        return check(s, t, s.length()-1, t.length()-1);
    }
};

// iterative and efficient approach
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) {
            return true;
        }
        int i1=0, i2=0;
        while(i2 < t.length()) {
            if(s[i1] == t[i2]) {
                i1++;
                i2++;
            } else {
                i2++;
            }
        }
        if(i1 == s.length()) return true;
        return false;
    }
};
