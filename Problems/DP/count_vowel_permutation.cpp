// Problem link:- 
// Difficulty:- Hard

// Brute force O(5 ^ N)
const int MOD = 1e9 + 7;

class Solution {
public:
    int solve(string& curr, int n) {
        if(n == 0) return 1;
        
        int ans = 0;
        vector<char> temp;
        
        if(curr.length() == 0) {
            temp = {'a', 'e', 'i', 'o', 'u'};
        } else {
            switch(curr[curr.length() - 1]) {
                case 'a':
                    temp = {'e'};
                    break;
                case 'e':
                    temp = {'a', 'i'};
                    break;
                case 'i':
                    temp = {'a', 'e', 'o', 'u'};
                    break;
                case 'o':
                    temp = {'i', 'u'};
                    break;
                default:
                    temp = {'a'};
            }
        }
        
        for(auto ch : temp) {
            curr.push_back(ch);
            ans = (ans + solve(curr, n - 1)) % MOD;
            curr.pop_back();
        }
        
        return ans;
    }
    
    int countVowelPermutation(int n) {
        string s = "";
        return solve(s, n);
    }
};


// Optimized dp O(5 * N)
const int MOD = 1e9 + 7;
class Solution {
    const vector<vector<int>> mappings{{1}, {0,2}, {0,1,3,4}, {2,4}, {0}, {0,1,2,3,4}};
    int dp[6][20001]{};
public:
    int countVowelPermutation(int rem, int prev = 5) {
        if(!rem) return 1;                        
        if(dp[prev][rem]) return dp[prev][rem];    
      
        for(auto c : mappings[prev])
            dp[prev][rem] = (dp[prev][rem] + countVowelPermutation(rem - 1, c)) % MOD;  
      
        return dp[prev][rem];
    }
};
