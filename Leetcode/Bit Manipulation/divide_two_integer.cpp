// Problem link: https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) {
            return 1;
        }
        
        int maxLim = 2147483647;
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        
        while(a >= b){  
            short q = 0;
            while(a > (b<<(q+1)))
                q++;
            ans += (1<<q); 
            a = a - (b<<q);  
        }
        if(ans == (1<<31) and sign == 1)  
            return maxLim;
        
        return ans * sign;
    }
};
