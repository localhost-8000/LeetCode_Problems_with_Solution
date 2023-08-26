// Problem link:- https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int n = matrix.size();
        int c = n - 1;
        int cnt = 0;
        
        for(int i=0; i<n; ++i) {
            while(c >= 0 && matrix[i][c] > x) c--;
            cnt += (c + 1);
        }
        
        return cnt;
    }
};
