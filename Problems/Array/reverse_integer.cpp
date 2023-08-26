// problem link: https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int min_limit = numeric_limits<int>::min();
        int max_limit = numeric_limits<int>::max();
        
        int rev = 0;
        while( x ) {
            int curr_dig = x % 10;
            if(rev > max_limit / 10 || (rev == max_limit/10 && curr_dig > 7)) {
                return 0;
            }
            if(rev < min_limit/10 || (rev == min_limit/10 && curr_dig < -8)) {
                return 0;
            }
            rev = rev * 10 + curr_dig;
            x /= 10;
        }
        return rev;
    }
};
