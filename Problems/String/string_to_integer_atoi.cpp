// Problem link:- https://leetcode.com/problems/string-to-integer-atoi


class Solution {
public:
    bool isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }
    
    int myAtoi(string s) {
        int n = s.length();
        
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        
        int res_sign = 1;
        if(i < n && s[i] == '+') {
            i++;
        } else if(i < n && s[i] == '-') {
            res_sign = -1;
            i++;
        }
        
        int num = 0;
        int upper_limit = INT_MAX / 10;
        
        for(; i<n; ++i) {
            char ch = s[i];
            
            if(isNumber(ch)) {
                int dig = ch - '0';
                
                if((num > upper_limit) || (num == upper_limit && dig > INT_MAX % 10)) {
                    return res_sign == 1 ? INT_MAX : INT_MIN;
                }
        
                num = num * 10 + dig;
            }
            else break;
        }
        
        
        return res_sign * num;
    }
};
