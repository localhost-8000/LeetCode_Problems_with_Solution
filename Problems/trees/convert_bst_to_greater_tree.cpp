// Problem link:- https://leetcode.com/problems/convert-bst-to-greater-tree/
// Difficulty:- Medium


class Solution {
    int k;
public:
    TreeNode* helper(TreeNode* root) {
        if(root == nullptr) return nullptr;
        
        root->right = helper(root->right);
        k += root->val;
        root->val = k;
        root->left = helper(root->left);
        
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        
        k = 0;
        return helper(root);
    }
};
