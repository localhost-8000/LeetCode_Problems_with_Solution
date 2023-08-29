// Problem link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
// Difficulty: Medium

// Key point: How to make teams of size 2 having equal skill? Having one biggest element and one smallest element in the pair.


// Optimal solution
// TC: O(n * logn)  SC: O(n)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = size(skill);
        sort(begin(skill), end(skill));

        unordered_map<int, int> store;
        long long chemistry = 0;

        for (int i=0; i<n/2; ++i) {
            store[skill[i] + skill[n-1-i]]++;
            chemistry += (skill[i] * skill[n-1-i]);
        }
        return store.size() == 1 ? chemistry : -1;
    }
};