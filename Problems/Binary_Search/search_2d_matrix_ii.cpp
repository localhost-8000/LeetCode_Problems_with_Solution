// Problem link:- 

// O(m * log(n))...
class Solution {
public:
    bool targetFound(vector<int>& arr, int c, int key) {
        int left = 0, right = c - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            int curr = arr[mid];
            
            if(curr == key) return true;
            
            else if(curr > key) right = mid - 1;
            
            else left = mid + 1;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = r ? matrix[0].size() : 0;
        
        for(int i = 0; i < r; ++i) {
            int low = matrix[i][0];
            int high = matrix[i][c - 1];
            
            if(target >= low && target <= high) {
                if(targetFound(matrix[i], c, target)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


// O(m + n)...
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = r ? matrix[0].size() : 0;
        
        int low = 0, high = c - 1;
        
        while(low < r && high >= 0) {
            int curr = matrix[low][high];
            
            if(curr == target) return true;
            
            else if(curr > target) high--;
            
            else low++;
        }
        
        return false;
    }
};
