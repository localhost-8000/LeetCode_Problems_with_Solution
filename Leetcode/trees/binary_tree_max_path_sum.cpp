// Problem link:- https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int solve(TreeNode* root, int &ans) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) {
            ans = max(ans, root->val);
            return root->val;
        }
        
        
        int root_data = root->val;
        
        int left = solve(root->left, ans);
        int left_max = left + root_data;
        
        int right = solve(root->right, ans);
        int right_max = right + root_data;
        
        int subtree_max = root_data + left + right;
        
        int curr_ans = max({root_data, left_max, right_max});
        
        ans = max({ans, curr_ans, subtree_max});
        
        return curr_ans;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int ans = INT_MIN;
        int res = solve(root, ans);
        
        return max(ans, res);        
    }
};
