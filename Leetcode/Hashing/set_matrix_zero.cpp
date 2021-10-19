// Problem link: https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int rf = 0;
        int cf = 0;
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(matrix[i][j] == 0) {
                    rf = (i == 0) ? 1 : rf;
                    cf = (j == 0) ? 1 : cf;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<r; ++i) {
            for(int j=1; j<c; ++j) {
                matrix[i][j] = (matrix[i][0] == 0 || matrix[0][j] == 0) ? 0 : matrix[i][j];       
            }
        }
        
        if(rf) {
            for(int i=0; i<c; ++i) {
                matrix[0][i] = 0;
            }
        }
        if(cf) {
            for(int i=0; i<r; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
