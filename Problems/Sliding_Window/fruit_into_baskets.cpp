// Problem link:- https://leetcode.com/problems/fruit-into-baskets
// Difficulty:- Medium

// Longest subarray with two unique elements approach
// TC:- O(n)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        
        unordered_map<int, int> umap;
        int i = 0, j = 0;
        int ans = 0;
        
        while(j < n) {
            umap[fruits[j]]++;
            if(umap.size() > 2) {
                while(umap.size() > 2) {
                    if(--umap[fruits[i]] == 0) umap.erase(fruits[i]);
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        
        
        return ans;
    }
};
