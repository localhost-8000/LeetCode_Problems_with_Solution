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

// efficient approach...
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        
        vector<int> ans;
        if(m == 0 || n == 0) return ans;

        int min_r = 0;
        int min_c = 0;
        
        int max_r = m - 1;
        int max_c = n - 1;
        
        int cnt = 1;
        int total_elem = m * n;
        
        while(cnt <= total_elem) {
            // top...
            for(int i = min_r, j = min_c; j <= max_c && cnt <= total_elem; ++j) {
                ans.push_back(matrix[i][j]);
                cnt++;
            }
            min_r++;
            
            // right..
            for(int i = min_r, j = max_c; i <= max_r && cnt <= total_elem; ++i) {
                ans.push_back(matrix[i][j]);
                cnt++;
            }
            max_c--;
            
            // bottom...
            for(int i = max_r, j = max_c; j >= min_c && cnt <= total_elem; --j) {
                ans.push_back(matrix[i][j]);
                cnt++;
            }
            max_r--;
            
            // left...
            for(int i = max_r, j = min_c; i >= min_r && cnt <= total_elem; --i) {
                ans.push_back(matrix[i][j]);
                cnt++;
            }
            min_c++;
        }
        
        return ans;
    }
};
