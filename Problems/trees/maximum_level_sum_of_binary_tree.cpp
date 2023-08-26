// Problem link:- https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Difficulty:- Medium

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int val = INT_MIN, level = 1;
        int ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            
            while(n--) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            if(sum > val) {
                val = sum;
                ans = level;
            }
            
            level++;
        }
        
        return ans;
    }
};
