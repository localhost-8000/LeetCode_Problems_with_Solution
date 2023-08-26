// Problem link:- https://leetcode.com/problems/house-robber-iii


// DP optimized solution...
class Solution {
public:
    int findMaxAmount(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        
        if(dp.find(root) != dp.end()) return dp[root];
        
        int pick_current = root->val;
        
        int pick_left_after_skipping_one = root->left 
            ? findMaxAmount(root->left->left, dp) + findMaxAmount(root->left->right, dp) 
            : 0;
        
        int pick_right_after_skipping_one = root->right 
            ? findMaxAmount(root->right->left, dp) + findMaxAmount(root->right->right, dp) 
            : 0;
        
        pick_current += (pick_left_after_skipping_one + pick_right_after_skipping_one);
        
        int ignore_current = findMaxAmount(root->left, dp) + findMaxAmount(root->right, dp);
        
        
        return dp[root] = max(pick_current, ignore_current);
    }
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        unordered_map<TreeNode*, int> dp;
        return findMaxAmount(root, dp);
    }
};
