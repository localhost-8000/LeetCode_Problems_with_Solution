// Problem link:- https://leetcode.com/problems/cousins-in-binary-tree


class Solution {
    int x_height, y_height;
    TreeNode *x_parent, *y_parent;
public:
    void solve(TreeNode* root, int x, int y, int height, TreeNode* parent) {
        if(root == nullptr) return;
        
        if(root->val == x) {
            x_height = height;
            x_parent = parent;
            return;
        }
        
        if(root->val == y) {
            y_height = height;
            y_parent = parent;
            return;
        }
        
        solve(root->left, x, y, height + 1, root);
        solve(root->right, x, y, height + 1, root);
        
        return;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val ==x || root->val == y) return false;
        
        solve(root, x, y, 0, nullptr);
        
        if(x_height == y_height && x_parent != y_parent) {
            return true;
        }
        return false;
    }
};
