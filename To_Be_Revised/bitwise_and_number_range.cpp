// Problem link:- https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) return 0;
        
        int m = 1;
        while(left != right) {
            left >>= 1;
            right >>= 1;
            m <<= 1;
        }
        
        return left * m;
    }
};
