// Problem link:- https://leetcode.com/problems/basic-calculator-ii

class Solution {
public:
    bool isNum(char c) {
        if(c >= '0' && c <= '9') return true;
        return false;
    }
    
   
    int calculate(string s) {
        int n = s.length();
        
        stack<int> nums;
        int current_num = 0;
        char current_operator = '+';
        
        for(int i = 0; i<n; ++i) {
            char ch = s[i];
            
            if(isNum(ch)) {
                current_num = (current_num * 10) + (ch - '0');
            }
            
            if(!isNum(ch) && ch != ' ' || i == n - 1) {
                
                if(current_operator == '+') nums.push(current_num);
                
                else if(current_operator == '-') nums.push(-current_num);
                
                else if(current_operator == '*') {
                    int top_num = nums.top();
                    nums.pop();
                    nums.push(top_num * current_num);
                    
                } else if(current_operator == '/') {
                    int top_num =  nums.top();
                    nums.pop();
                    nums.push(top_num / current_num);
                }
                
                current_operator = ch;
                current_num = 0;
            }
        }
        
        int ans = 0;
        while(!nums.empty()) {
            ans += nums.top();
            nums.pop();
        }
        
        return ans;
    }
};
