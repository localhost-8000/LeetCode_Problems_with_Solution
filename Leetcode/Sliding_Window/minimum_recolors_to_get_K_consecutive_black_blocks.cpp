// Problem link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
// Difficulty: Easy

// Optimal solution
// TC: O(n)  SC: O(n)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        vector<int> pre_sum(n + 1, 0);

        // compute prefix sum of the white block
        for (int i=1; i<=n; ++i) {
            if (blocks[i-1] == 'W') {
                pre_sum[i]++;
            }
            pre_sum[i] += pre_sum[i-1];
        }

        // initialize ans to for the first k block
        int ans = pre_sum[k] - pre_sum[0];

        for (int i=k+1; i<=n; ++i) {
            // calculate required recolors using the prefix sum array
            int curr_req = pre_sum[i] - pre_sum[i-k];
            ans = min(ans, curr_req);
        }
        
        return ans;
    }
};
