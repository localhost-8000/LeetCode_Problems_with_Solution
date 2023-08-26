// Problem link-------
// https://leetcode.com/problems/container-with-most-water/

// Brute force approach.....
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        
        for(int i=0; i<n-1; ++i) {
            int curr_left = height[i];
            for(int j=i+1; j<n; ++j) {
                int curr_right = height[j];
                int curr_diff = j - i;
                int curr_ans = min(curr_left, curr_right) * curr_diff;
                ans = max(ans, curr_ans);
            }
        }        
        return ans;  
    }
};

// Time complexity = O(N*N)
// Space complexity = O(1)

// Optimize approach....
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        
        int left = 0, right = n-1;
        
        while(left < right) {
            int diff = right - left;
            int curr_ans = diff * min(height[right], height[left]);
            ans = max(ans, curr_ans);
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return ans;  
    }
};

// Time complexity = O(N)
// Space complexity = O(1)
