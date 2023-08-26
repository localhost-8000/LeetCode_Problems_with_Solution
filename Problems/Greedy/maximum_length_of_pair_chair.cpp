// Problem Link: https://leetcode.com/problems/maximum-length-of-pair-chain/description/
// Difficulty: Medium

// Optimal solution
// TC: O(n * logn)  SC: O(1)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = size(pairs);

        // sort vector based on ascending order of pairs[][1]
        sort(pairs.begin(), pairs.end(), [](vector<int> p1, vector<int> p2) {
            if (p1[1] < p2[1]) return true;
            if (p1[1] > p2[1]) return false;
            return p1[0] <= p2[0] ? true : false;
        });

        int cnt = 0;
        int prev = INT_MIN;

      // Optimally calculate the following chain
        for (auto p : pairs) {
            if (p[0] > prev) {
                cnt++;
                prev = p[1];
            }
        }
        return cnt;
    }
};
