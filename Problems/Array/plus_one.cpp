// problem link...
// https://leetcode.com/problems/plus-one/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        vector<int> ans;
        for(int i=n-1; i>=0; --i) {
            int sum = carry + digits[i];
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        if(carry != 0) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// time complexity = O(N)
