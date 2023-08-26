// Problem link:- https://leetcode.com/problems/binary-tree-cameras/
// Difficulty:- Hard


class Solution {
    int ans;
    unordered_set<TreeNode*> visited;
public:
    void dfs(TreeNode *root, TreeNode* parent) {
        if(root == nullptr) return;
        
        dfs(root->left, root);
        dfs(root->right, root);
        
        if(parent == nullptr && visited.find(root) == end(visited) || visited.find(root->left) == end(visited) || visited.find(root->right) == end(visited)) {
            ans++;
            visited.insert(root);
            visited.insert(parent);
            visited.insert(root->left);
            visited.insert(root->right);
        }
    }
    
    int minCameraCover(TreeNode* root) {
        ans = 0;
        visited.insert(nullptr);
        
        dfs(root, nullptr);
        return ans;
    }
};
