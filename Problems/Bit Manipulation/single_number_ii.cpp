// Problem link:- https://leetcode.com/problems/single-number-ii/
// Difficulty:- Medium

class Solution {
public:
    void setBits(long long n, vector<int>& bit) {
        int i=0;
        while(n) {
            int curr_bit = 1 & n;
            bit[i++] += curr_bit;
            n = n >> 1;
        }
    }
    
    int singleNumber(vector<int>& nums) {
        vector<int> pos_bit(64, 0);
        vector<int> neg_bit(64, 0);
        
        for(int& num : nums) {
            if(num >= 0) setBits(num, pos_bit);
            else setBits((long long)abs(num), neg_bit);
        }
        
        long long ans = 0;
        
        for(int i=0; i<64; ++i) {
            pos_bit[i] %= 3;
            ans += (pos_bit[i] == 1) ? 1 << i : 0;
        }
        
        if(ans == 0) {
            for(int i=0; i<64; ++i) {
                neg_bit[i] %= 3;
                ans += (neg_bit[i] == 1) ? 1 << i : 0;
            } 
            ans *= -1;
        }
        
        return ans;
    }
};
