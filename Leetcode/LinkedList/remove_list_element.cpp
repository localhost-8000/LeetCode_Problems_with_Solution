// Problem link: https://leetcode.com/problems/remove-linked-list-elements/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* prev = head;
        ListNode* root = head;
        while(root) {
            if(root->val == val) {
                prev->next = root->next;
                
            } else {
                prev = root; 
            }
            root = root->next;
        }
        if(head->val == val) {
            if(head->next) {
                return head->next;
            }
            return NULL;
        }
        
        return head;
    }
};
