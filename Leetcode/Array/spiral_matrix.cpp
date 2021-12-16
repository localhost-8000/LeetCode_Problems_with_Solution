// Problem link:- https://leetcode.com/problems/spiral-matrix


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        
        vector<int> ans;
        
        for(int i = 0; i<(m + 1) / 2; ++i) {
            int row = m - 2 * i;
            int col = n - 2 * i;
            
            if(row <= 0 || col <= 0) break;
            
            int r = i, c = i;
            
            // if only one row present...
            if(row == 1) {
                for(c = i; c < col + i; ++c) ans.push_back(matrix[r][c]);
                break;
            }
            // if only column present...
            if(col == 1) {
                for( ; r < row + i; ++r) ans.push_back(matrix[r][c]);
                break;
            }
            
            // first row traversal..
            for(c = i; c < col + i; ++c) ans.push_back(matrix[r][c]);        
            c--;
            r++;
            
            // last column traversal..
            for( ; r < row + i; ++r) ans.push_back(matrix[r][c]);
            r--;
            c--;
            
            // last row traversal...
            for( ; c >= i; --c) ans.push_back(matrix[r][c]);
            c++;
            r--;
            
            // first column traversal...
            for( ; r > i; --r) ans.push_back(matrix[r][c]);
        }
        
        return ans;
    }
};
