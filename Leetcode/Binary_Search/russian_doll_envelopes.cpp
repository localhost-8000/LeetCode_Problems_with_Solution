// Problem link:- 
// Difficulty:- Hard

// Brute force DP method.. O(n^2)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        
        int ans = 0;
        vector<int> dp(n, 1);
        
        for(int i=0; i<n; ++i) {
            int big_w = envelopes[i][0];
            int big_h = envelopes[i][1];
            
            for(int j=0; j<i; ++j) {
                int curr_w = envelopes[j][0];
                int curr_h = envelopes[j][1];
                
                if(curr_w < big_w && curr_h < big_h) dp[i] = max(dp[i], dp[j] + 1);                       }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

// O(nLogn)..
class Solution {
    struct customSort{
        bool operator()(vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        }  
    };
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), customSort());
        
        vector<int> arr;
        
        for(auto env : envelopes) {
            int h = env[1];
            auto low = lower_bound(arr.begin(), arr.end(), h) - arr.begin();
            if(low == arr.size()) arr.push_back(h);
            else arr[low] = h;
        }
        
        return arr.size();
    }
};

// Same as upper with reduced line of code
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envs) {
        sort(envs.begin(), envs.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        vector<int> arr;
        
        for (auto e : envs) {
            int h = e[1];
            
            auto itr = lower_bound(arr.begin(), arr.end(), h);
            
            if (itr == arr.end()) arr.push_back(h);
            else *itr = h;
        }
        return arr.size();
    }
};
