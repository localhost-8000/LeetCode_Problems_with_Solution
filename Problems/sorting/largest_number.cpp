// Problem link:- https://leetcode.com/problems/largest-number


class Solution {
    static bool myComp(const string& s1, const string& s2) {
        string res1 = s1 + s2;
        string res2 = s2 + s1;
        return res1 > res2;
    }
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(const int &x : nums) {
            strs.push_back(to_string(x));
        }
        
        sort(strs.begin(), strs.end(), myComp);
        
        if(strs[0] == "0") return "0";
        
        string ans = "";
        for(const string &s : strs) {
            ans += s;
        }
        
        return ans;
    }
};
