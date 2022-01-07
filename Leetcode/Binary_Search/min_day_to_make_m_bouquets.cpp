// Problem link:- https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool isPossibleToMakeBouquets(int day, vector<int>& bloomDay, int m, int k) {
        int in_row = 0;
        
        for(const int &curr_day : bloomDay) {
            
            if(curr_day <= day) {
                in_row++;
            } else {
                in_row = 0;
                continue;
            }
            
            if(in_row == k) {
                in_row = 0;
                m--;
            }
            
            if(m == 0) return true;
        }
        
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
              
        int low = 1, high = 1e9;
        int ans = -1;
        
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
       
            if(isPossibleToMakeBouquets(mid, bloomDay, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
