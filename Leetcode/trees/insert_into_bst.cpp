// Problem link:- https://leetcode.com/problems/insert-into-a-binary-search-tree

// iterative approach..
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        TreeNode* prev = root;
        
        while(temp) {
            prev = temp;
            if(temp->val < val) temp = temp->right;
            else temp = temp->left;
        }
        
        TreeNode* node = new TreeNode(val);
        if(prev == nullptr) return node;
        
        if(prev->val < val) {
            prev->right = node;
        } else {
            prev->left = node;
        }
        
        return root;
    }
};

// recursive approach..
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        
        int curr_node_val = root->val;
        
        if(curr_node_val < val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        
        return root;
    }
};
