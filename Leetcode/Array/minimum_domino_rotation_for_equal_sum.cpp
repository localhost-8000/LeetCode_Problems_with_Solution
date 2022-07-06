// Problem link:- https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// Difficulty:- Medium


class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int store[7];
        memset(store, 0, sizeof(store));
        
        for(int i=0; i<n; ++i) {
            store[tops[i]]++;
            if(tops[i] != bottoms[i]) {
                store[bottoms[i]]++;
            }
        }
        
        int same_dice = -1;
        
        for(int i=1; i<=6; ++i) {
            if(store[i] == n) {
                same_dice = i;
                break;
            }
        }
        
        if(same_dice == -1) return -1;
        
        int t = 0, b = 0;
        for(int i=0; i<n; ++i) {
            if(tops[i] == bottoms[i]) continue;
            t += tops[i] == same_dice ? 1 : 0;
            b += bottoms[i] == same_dice ? 1 : 0;
        }
        
        return min(t, b);
    }
};
