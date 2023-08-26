// Problem link:- https://leetcode.com/problems/maximum-product-of-word-lengths/
// Difficulty:- Medium

// O(n^2 * 26)...
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unordered_set<char> us[n];
        
        for(int i=0; i<n; ++i) {
            string word = words[i];
            for(char c : word) us[i].insert(c);
        }
        
        int ans = 0;
        
        for(int i=0; i<n-1; ++i) {
            int len1 = words[i].length();
            for(int j=i+1; j<n; ++j) {
                bool flag = false;
                
                for(char c : us[j]) {
                    if(us[i].find(c) != us[i].end()) {
                        flag = true;
                        break;
                    }
                }
                
                if(flag) continue;
                
                int len2 = words[j].length();
                ans = max(ans, len1 * len2);
            }
        }
        
        return ans;
    }
};

// using bit masking..O(n^2).. efficient than above
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        
        int ans = 0;
        vector<int> bit_mask(n, 0);
        
        for(int i=0; i<n; ++i) {
            string word = words[i];
            int len1 = word.length();
            
            for(char& c : word) bit_mask[i] |= 1 << (c - 'a');
            
            for(int j=0; j<i; ++j) {
                if((bit_mask[i] & bit_mask[j]) == 0) {
                    ans = max(ans, (int)(len1 * size(words[j])));
                }
            }
        }
        
        return ans;
    }
};
