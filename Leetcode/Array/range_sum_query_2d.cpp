// Problem link:- https://leetcode.com/problems/range-sum-query-2d-immutable/
// Difficulty:- Medium

class NumMatrix {
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = r ? mat[0].size() : 0;
        
        matrix.resize(r, vector<int>(c, 0));
        matrix[0][0] = mat[0][0];
        
        for(int i=1; i<r; ++i) {
            matrix[i][0] = matrix[i-1][0] + mat[i][0];
        }
        
        for(int j=1; j<c; ++j) {
            matrix[0][j] = matrix[0][j-1] + mat[0][j];
        }
        
        for(int i=1; i<r; ++i) {
            for(int j=1; j<c; ++j) {
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1] + mat[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int upper_r = min(row1, row2) - 1;
        int lower_r = max(row1, row2);
        int right_c = max(col1, col2);
        int left_c = min(col1, col2) - 1;
        
        int upper_sum = 0;
        
        if(upper_r < 0) upper_sum = 0;
        else if(left_c < 0) upper_sum = matrix[upper_r][right_c];
        else upper_sum = matrix[upper_r][right_c] - matrix[upper_r][left_c];
        
        int left_sum = left_c < 0 ? 0 : matrix[lower_r][left_c];
        
        return matrix[lower_r][right_c] - upper_sum - left_sum;
    }
};
