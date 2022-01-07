// Problem link:- https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    bool isPossibleToMakeBouquets(long long day, vector<int>& bloomDay, int m, int k) {
        int in_row = 0;
        int n = bloomDay.size();
        
        for(int i=0; i<n; ++i) {
            if(bloomDay[i] <= day) {
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
        
        return m == 0;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        
        int low = 1, high = 1e9;
        int ans = -1;
        
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
       
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
