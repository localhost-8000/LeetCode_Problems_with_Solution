// Problem link:- https://leetcode.com/problems/spiral-matrix-ii


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int min_r = 0;
        int min_c = 0;
        
        int max_r = n - 1;
        int max_c = n - 1;
        
        int cnt = 1;
        int total_elem = n * n;
        
        while(cnt <= total_elem) {
            // filling top...
            for(int i = min_r, j = min_c; j <= max_c && cnt <= total_elem; ++j) ans[i][j] = cnt++;
            min_r++;
            
            // filling right..
            for(int i = min_r, j = max_c; i <= max_r && cnt <= total_elem; ++i) ans[i][j] = cnt++;
            max_c--;
            
            // filing bottom...
            for(int i = max_r, j = max_c; j >= min_c && cnt <= total_elem; --j) ans[i][j] = cnt++;
            max_r--;
            
            // filling left...
            for(int i = max_r, j = min_c; i >= min_r && cnt <= total_elem; --i) ans[i][j] = cnt++;
            min_c++;
        }
        
        return ans;
    }
};
