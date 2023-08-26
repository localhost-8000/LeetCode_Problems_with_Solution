// Problem link:- https://leetcode.com/problems/delete-node-in-a-bst/
// Difficulty:- Medium


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        int curr = root->val;
        
        if(curr == key) {
            if(!root->left && !root->right) return nullptr;
            if(!root->left || !root->right) return root->left ? root->left : root->right;
            
            TreeNode *temp = root->left;
            while(temp->right) temp = temp->right;
            
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }
        else if(curr < key) root->right = deleteNode(root->right, key);
        else root->left = deleteNode(root->left, key);
        
        return root;
    }
};
