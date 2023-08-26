// Problem link:- https://leetcode.com/problems/car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> pre_sum(1001, 0);
        
        for(auto &arr : trips) {
            int psngr = arr[0];
            int src = arr[1];
            int dest = arr[2];
            
            pre_sum[src] += psngr;
            pre_sum[dest] -= psngr;
        }
        
        for(int i=0; i<1001; ++i) {
            pre_sum[i] += (i == 0) ? 0 : pre_sum[i - 1];
            
            if(pre_sum[i] > capacity) return false;
        }
        
        return true;
    }
};
