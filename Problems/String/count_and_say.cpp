// Problem link:- https://leetcode.com/problems/count-and-say


class Solution {
public:
    string solve(int n, string& res) {
        if(n == 0) return res;
        
        int len = res.length();
        string temp = "";
        int cnt = 1;
        char num = res[0];
        
        for(int i = 1; i < len; ++i) {
            char curr = res[i];
            
            if(curr == num) cnt++;
            else {
                temp += (cnt + '0');
                temp += num;
                
                cnt = 1;
                num = curr;
            }
        }
        
        temp += (cnt + '0');
        temp += num;
        
        return solve(n - 1, temp);
        
    }
    string countAndSay(int n) {
        
        string result = "1";
        if(n == 1) return result;
        
        return solve(n - 1, result);
        
    }
};
