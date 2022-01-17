// Problem link:- https://leetcode.com/problems/sum-root-to-leaf-numbers

class Solution {
    int ans;
public:
    void dfs(TreeNode* root, int num) {
        
        int curr = (num * 10) + root->val;
        
        if(root->left == nullptr && root->right == nullptr) {
            ans += curr;
            return;
        }
        
        if(root->left) dfs(root->left, curr);
        if(root->right) dfs(root->right, curr);
        
        return;
    }
  
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        ans = 0;
        dfs(root, 0);
        return ans;;
    }
};
