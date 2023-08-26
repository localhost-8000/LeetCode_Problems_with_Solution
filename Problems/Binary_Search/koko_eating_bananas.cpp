// Problem link:- https://leetcode.com/problems/koko-eating-bananas/
// Difficulty:- Medium


class Solution {
public:
    int possibleHourtoEat(vector<int>& piles, int rate) {
        int cnt = 0;
        for(int &pile : piles) {
            cnt += (pile % rate == 0) ? pile / rate : (pile / rate) + 1;
        }
        return cnt;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(possibleHourtoEat(piles, mid) <= h) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
