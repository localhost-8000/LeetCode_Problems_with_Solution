// Problem link:- https://leetcode.com/problems/flatten-binary-tree-to-linked-list

class Solution {
public:
    void flatten(TreeNode *root) {
		TreeNode* curr = root;
		while(curr) {
			if(curr->left) {
				TreeNode* pre = curr->left;
				while(pre->right) {
					pre = pre->right;
				}
				pre->right = curr->right;

				curr->right = curr->left;
				curr->left = NULL;
			}
			curr = curr->right;
		}
    }
};
