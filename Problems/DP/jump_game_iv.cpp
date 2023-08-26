// Problem link:- https://leetcode.com/problems/jump-game-vi/
// Difficulty:- Medium

// Brute force optimized with DP.. O(k*n)
class Solution {
public:
    int helper(vector<int>& nums, int k, int i, vector<int>& dp) {
        int n = nums.size();
        if(i == n - 1) return nums[i];
        
        if(dp[i] != INT_MIN) return dp[i];
        
        int ans = INT_MIN;
        for(int j = i + 1; j <= min(i + k, n - 1); ++j) {
            int curr_ans = helper(nums, k, j, dp);
            ans = max(curr_ans, ans);
        }
        
        return dp[i] = ans + nums[i];
    }
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        
        return helper(nums, k, 0, dp);
    }
};

// Optimized using multiset.. O(N * logK)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n, INT_MIN);
        multiset<int> ms;
        
        dp[0] = nums[0];
        ms.insert(nums[0]);
        
        for(int i=1; i<n; ++i) {
            if(i > k) ms.erase(ms.find(dp[i - k - 1]));
            
            dp[i] = *ms.rbegin() + nums[i];
            ms.insert(dp[i]);
        }
        
        return dp.back();
    }
};

// More Optimization... O(n)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n, INT_MIN);
        deque<int> dq;
        
        dp[0] = nums[0];
        dq.push_back(0);
        
        for(int i=1; i<n; ++i) {
            if(dq.front() < i - k) dq.pop_front();
            dp[i] = dp[dq.front()] + nums[i];
            while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        
        return dp.back();
    }
};
