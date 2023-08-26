// Problem link:- https://leetcode.com/problems/ugly-number-ii/

// Naive method....
class Solution {
public:
    bool isUglyPrime(int n) {
        
        while((n & 1) == 0) {
            n = (n >> 1);
        }
        
        for(int i = 3; i <= sqrt(n); i += 2) {
            if(i > 5) return false;
            
            while(n % i == 0) n /= i;
        }
        
        if(n > 5) return false;
        
        return true;
    }
    
    int nthUglyNumber(int n) {
        int num = 1;
        int ans = 1;
        for(int i = 1; i <= n; ) {
            if(isUglyPrime(num)) {
                ans = num;
                num++;
                i++;
            } else {
                num++;
            }
        }
        
        return ans;
    }
};


// optimized approached...
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        
        vector<int> dp(n);
        
        int k2 = 0, k3 = 0, k5 = 0;
        dp[0] = 1;
        
        for(int i = 1; i < n; ++i) {
            int curr_to = dp[k2] * 2;
            int curr_th = dp[k3] * 3;
            int curr_fiv = dp[k5] * 5;
            
            int minm = min({curr_to, curr_th, curr_fiv});
            dp[i] = minm;
            
            if(minm == curr_to) k2++;
            if(minm == curr_th) k3++;
            if(minm == curr_fiv) k5++;
        }
        
        return dp[n - 1];
    }
};
