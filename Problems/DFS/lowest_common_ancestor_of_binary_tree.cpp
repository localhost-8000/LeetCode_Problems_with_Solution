// Problem link:- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree


class Solution {
    TreeNode* ans;
public:
    bool isContains(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return false;
        
        bool left = false;
        bool right = false;
        bool mid = false;
    
        left = isContains(root->left, p, q);
        right = isContains(root->right, p, q);
        mid = (root->val == p->val) || (root->val == q->val);
        
        if((mid && left) || (mid && right) || (left & right)) {
            ans = root;
        }
        
        return left || right || mid;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        isContains(root, p, q);
        return ans;
    }
};
