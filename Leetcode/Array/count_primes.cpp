// Problem link:- https://leetcode.com/problems/count-primes/
// Difficulty:- Medium

// using sieve algorithm... O(n * log(log(n)))..
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        for(int i=2; i*i < n; ++i) {
            if(!prime[i]) continue;
            for(int j=i*i; j<n; j += i) prime[j] = false;
        }
        
        int cnt = 0;
        for(int i=2; i<n; ++i) if(prime[i]) cnt++;
        return cnt;
    }
};
