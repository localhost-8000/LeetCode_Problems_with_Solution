// Problem link:- https://leetcode.com/problems/trim-a-binary-search-tree
// Difficulty level:- Medium

class Solution {
public:
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return nullptr;
        
        int val = root->val;

        if(val < low) return trimBST(root->right, low, high);
        else if(val > high) return trimBST(root->left, low, high);
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};
