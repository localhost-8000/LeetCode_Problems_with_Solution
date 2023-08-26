// Problem link:- https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int max_prod = nums[0];
        int min_prod = nums[0];
        
        for(int i=1; i<n; ++i) {
            int curr_elem = nums[i];
            // if current element is negative..swap the max and min products
            if(curr_elem < 0) {
                swap(max_prod, min_prod);
            }
            int curr_max_prod = curr_elem * max_prod;
            max_prod = max(curr_elem, curr_max_prod);
            
            int curr_min_prod = curr_elem * min_prod;
            min_prod = min(curr_elem, curr_min_prod);
            
            ans = max(ans, max_prod);
        }
        return ans;
    }
};
