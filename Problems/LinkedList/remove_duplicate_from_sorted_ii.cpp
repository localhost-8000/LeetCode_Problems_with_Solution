// Problem link:- https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Difficulty:- Medium


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *root = new ListNode(-1, head);
        ListNode *prev = root;
        ListNode *curr_node = head;
        
        while(curr_node) {
            if(curr_node->next && curr_node->val == curr_node->next->val) {
                while(curr_node->next && curr_node->val == curr_node->next->val) curr_node = curr_node->next;
                prev->next = curr_node->next;
            }
            else prev = prev->next;
            curr_node = curr_node->next;
        }
        
        return root->next;
    }
};
