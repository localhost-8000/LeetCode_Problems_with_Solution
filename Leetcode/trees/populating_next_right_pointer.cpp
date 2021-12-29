// Problem link:- https://leetcode.com/problems/populating-next-right-pointers-in-each-node

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            Node* next = nullptr;
            
            while( len-- ) {
                Node* topNode = q.front();
                q.pop();
                
                topNode->next = next;
                next = topNode;
                
                if(topNode->right) q.push(topNode->right);
                if(topNode->left) q.push(topNode->left);
            }
        }
        
        return root;
    }
};
