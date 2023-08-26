// Problem link:- https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Difficulty:- Medium


const int MOD = 1e9 + 7;

class Solution {
public:
    long long max(long long a, long long b) {
        return a < b ? b : a;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        
        long long height = 0, width = 0;
        long long curr_ans, ans = 0;
        int prev_cut = 0;
        
        for(int& curr_cut : horizontalCuts) {
            height = max(height, curr_cut - prev_cut);
            prev_cut = curr_cut;
        }
        
        height = max(height, h - prev_cut);
        prev_cut = 0;
        
        for(int& curr_cut : verticalCuts) {
            width = max(width, curr_cut - prev_cut);
            prev_cut = curr_cut;
            
            curr_ans = height * width;
            ans = max(ans, curr_ans);
        }
        
        width = max(width, w - prev_cut);
        curr_ans = height * width;
        
        ans = max(ans, curr_ans);
        
        return ans % MOD;
    }
};
