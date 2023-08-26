// Problem link:- https://leetcode.com/problems/maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = m ? mat[0].size() : 0;
        
        if(m == 0 || n == 0) return 0;
        
        int sq_len = INT_MIN;
        
        vector<vector<int>> matrix;
        
        // coverting char matrix into int matrix...
        for(int i=0; i<m; ++i) {
            vector<int> temp;
            
            for(int j=0; j<n; ++j) {
                
                int curr = mat[i][j] - '0';
                sq_len = max(sq_len, curr);
                temp.push_back(curr);
            }
            
            matrix.push_back(temp);
        }
 
        // for every element, check corner, up & left is available or not...
        for(int i=1; i<m; ++i) {
            
            for(int j=1; j<n; ++j) {
                
                int curr = matrix[i][j];
                
                if(curr != 0) {
                    
                    int corner = matrix[i-1][j-1];
                    int left = matrix[i][j-1];
                    int up = matrix[i-1][j];
                    
                    if(corner && left && up) {
                        
                        int mn = min({corner, left, up}) + 1;
                        sq_len = max(mn, sq_len);
                        matrix[i][j] = mn;
                    }
                }
            }
        }
        
        return sq_len * sq_len;
    }
};

// Space optimized approach...
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        
        if(m == 0 || n == 0) return 0;
        
        vector<int> dp(n + 1, 0);
        
        
        int prev = 0;
        int sq_len = 0;
        
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                
                int temp = dp[j];
                char curr = matrix[i-1][j-1];
                
                if(curr == '1') {
                    
                    dp[j] = min({dp[j-1], dp[j], prev}) + 1;
                    sq_len = max(sq_len, dp[j]);
                    
                } else {
                    
                    dp[j] = 0;
                }
                
                prev = temp;
            }
        }
        
        return sq_len * sq_len;
    }
};
