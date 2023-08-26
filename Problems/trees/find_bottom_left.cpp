// Problem link:- https://leetcode.com/problems/find-bottom-left-tree-value/

// left to right level order traversal...
class Solution {
public:
    
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*> track;
        track.push(root);
        
        while(!track.empty()) {
            
            TreeNode* top = track.front();
            ans = top->val;
            int curr_level_width = track.size();
            
            while(curr_level_width--) {
                TreeNode* curr = track.front();
                track.pop();
                if(curr->left) track.push(curr->left);
                if(curr->right) track.push(curr->right);
            }
            
        }
        return ans;
    }
};
