// Problem link:- https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;
        
        string ans = "";
        
        int l = 2*n, r = -2;
        
        for(int i=0; i<n; ++i) {
            l -= 2;
            r += 2;
            
            int steps = 1;
            for(int j = i; j < s.length(); ) {
                
                ans += s[j];
                
                if(l == 0 || r == 0) {
                    j += max(l, r);
                }
                else if(steps & 1) {
                    j += l;
                } else {
                    j += r;
                }
                steps++;
            }
        }
        
        return ans;
    }
};
