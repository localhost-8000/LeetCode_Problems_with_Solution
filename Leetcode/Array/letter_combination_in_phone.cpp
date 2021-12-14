// Problem link:- https://leetcode.com/problems/letter-combinations-of-a-phone-number

// Backtracking recursive approach...
class Solution {
    vector<string> numString;
    vector<string> ans;
public:
    Solution() {
        char ch = 'a';
        for(int i=2; i<=9; ++i) {
            string str;
            str = ch++;
            str += ch++;
            str += ch++;
            str = (i == 7 || i == 9) ? (str + ch++) : str;
            numString.push_back(str);
        }
    }
    
    void generateComb(const string digits, int p, string temp) {
        int len = digits.length();
        if(p >= len) {
            ans.push_back(temp);
            return;
        }
        
        int digit = digits[p] - '0';
        for(const char& ch : numString[digit - 2]) {
            generateComb(digits, p + 1, temp + ch);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;
        generateComb(digits, 0, "");
        return ans;
    }
};

// Optimized approach...
class Solution {
    vector<string> numString;
    vector<string> ans;
public:
    Solution() {
        numString = {"", 
                     "", "abc", "def", 
                     "ghi", "jkl", "mno", 
                     "pqrs", "tuv", "wxyz"};
    }
    
    void generateComb(const string digits) {
        ans.push_back("");
        
        for(const char& dig : digits) {
            int digit = dig - '0';
            
            vector<string> temp;
            for(const char& ch : numString[digit]) {
                
                for(auto res_char : ans) {
                    temp.push_back(res_char + ch);
                }
            }
            ans = temp;
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;
        
        generateComb(digits);
        
        return ans;
    }
};
