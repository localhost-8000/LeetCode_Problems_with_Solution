// Problem link:- https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

class Solution {
    int ans;
public:
    void solve(TreeNode* root, int curr_max, int curr_min) {
        if(root == nullptr) return;
        
        int val = root->val;
        int r1 = abs(curr_max - val);
        int r2 = abs(curr_min - val);
        
        int curr_res = max(r1, r2);
        ans = max(ans, curr_res);
        
        curr_max = max(curr_max, val);
        curr_min = min(curr_min, val);
        
        solve(root->left, curr_max, curr_min);
        solve(root->right, curr_max, curr_min);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        if(root == nullptr) return ans;
        
        solve(root, root->val, root->val);
        return ans;
    }
};

// little bit more optimized..
class Solution {
public:
    int solve(TreeNode* root, int curr_max, int curr_min) {
        if(root == nullptr) return curr_max - curr_min;
        
        int val = root->val;
        curr_max = max(curr_max, val);
        curr_min = min(curr_min, val);
        
        int left = solve(root->left, curr_max, curr_min);
        int right = solve(root->right, curr_max, curr_min);
        
        return max(left, right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
      
        if(root == nullptr) return 0;
        
        return solve(root, root->val, root->val);

    }
};
