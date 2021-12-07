// Problem link:- https://leetcode.com/problems/binary-tree-right-side-view/

// iterative approach :-
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> track;
        track.push(root);
        
        while(!track.empty()) {
            TreeNode* top = track.front();
            ans.push_back(top->val);
            int curr_level_width = track.size();
            
            while(curr_level_width--) {
                TreeNode* curr = track.front();
                track.pop();
                if(curr->right) track.push(curr->right);
                if(curr->left) track.push(curr->left);
            }
            
        }
        return ans;
    }
};

// Recursive approach...
class Solution {
    unordered_set<int> us;
public:
    void generateRightView(TreeNode* root, vector<int>& ans, int level) {
        if(root == nullptr) return;
        
        if(us.find(level) == us.end()) ans.push_back(root->val);
        
        us.insert(level);
        int next_level = level + 1;
        
        generateRightView(root->right, ans, next_level);
        generateRightView(root->left, ans, next_level);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        generateRightView(root, ans, 0);
        return ans;
    }
};
