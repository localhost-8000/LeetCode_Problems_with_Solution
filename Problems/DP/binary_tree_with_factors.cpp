// Problem link:- https://leetcode.com/problems/binary-trees-with-factors/
// Difficulty:- Medium


// O(n * n)
const int MOD = 1e9 + 7;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        vector<long> dp(n, 1);
        unordered_map<int, int> store;
        
        for(int i=0; i<n; ++i) store[arr[i]] = i;
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                int curr = arr[i];
                int left = arr[j];
                
                if(curr % left != 0) continue;
                int right = curr / left;
                if(store.find(right) != end(store)) dp[i] = (dp[i] + dp[j] * dp[store[right]]) % MOD;
            }
        }
        
        int ans = 0;
        for(auto num : dp) ans = (ans + num) % MOD;
        
        return ans;
    }
};
