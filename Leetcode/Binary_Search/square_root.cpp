// problem link:- https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0 || x == 1) {
            return x;
        }
        
        unsigned int low = 1, high = x, ans, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(x / mid == mid) {
                return mid;
            }
            else if(x / mid > mid){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
