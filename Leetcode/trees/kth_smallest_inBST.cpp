// Problem link:- https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    void inorder(TreeNode* root, int *cnt, int *ans) {
        if(root == nullptr) return;
        
        inorder(root->left, cnt, ans);
        
        (*cnt)--;
        
        if(*cnt == 0) {
            *ans = root->val;
            return;
        }
        
        inorder(root->right, cnt, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, &k, &ans);
        return ans;
    }
};
