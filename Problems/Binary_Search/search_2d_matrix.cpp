// Problem link:- https://leetcode.com/problems/search-a-2d-matrix

// basic approach, O(m + n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int row_containing_index = -1;
        for(int i=0; i<r; ++i) {
            int last_elem = matrix[i][c - 1];
            if(last_elem >= target) {
                row_containing_index = i;
                break;
            }
        }
        
        if(row_containing_index == -1) return false;
        
        for(int i=0; i<c; ++i) {
            int curr_elem = matrix[row_containing_index][i];
            if(curr_elem == target) return true;
        }
        return false;
    }
};

// Optimized approach, O(log(m) + log(n))
class Solution {
public:
    int findRowContainingTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int last_col = matrix[0].size() - 1;
        
        int top = 0, bottom = r - 1;
        while(top < bottom) {
            int mid = top + (bottom - top) / 2;
            int curr_elem = matrix[mid][last_col];
            if(curr_elem >= target) {
                bottom = mid;
            } else {
                top = mid + 1;
            }
        }
        return bottom;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        if(matrix[0][0] > target || matrix[r-1][c-1] < target) return false;
        
        
        int target_row = findRowContainingTarget(matrix, target);

        int left = 0, right = c - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int curr = matrix[target_row][mid];
            
            if(curr == target) return true;
            
            if(curr < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return false;
    }
};
