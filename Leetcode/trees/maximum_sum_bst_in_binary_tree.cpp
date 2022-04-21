// Problem link:- https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Difficulty:- Hard


class HelperNode {
public:
    int min, max, sum;
    
    HelperNode(int min, int max, int sum) {
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

class Solution {
    int ans;
public:
    HelperNode solve(TreeNode *root) {
        if(root == nullptr) {
            return HelperNode(INT_MAX, INT_MIN, 0);
        }
        
        HelperNode left = solve(root->left);
        HelperNode right = solve(root->right);
        
        int root_val = root->val;
        
        if(root_val < right.min && root_val > left.max) {
            int curr_sum = left.sum + right.sum + root_val;
            ans = max(ans, curr_sum);
            
            int new_minm = min(root_val, left.min);
            int new_maxm = max(root_val, right.max);
            
            return HelperNode(new_minm, new_maxm, curr_sum);
        }
        
        return HelperNode(INT_MIN, INT_MAX, 0);
    }
    
    int maxSumBST(TreeNode* root) {
        ans = 0;
        
        solve(root);
        
        return ans;
    }
};
