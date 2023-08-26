// Problem link: https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    ListNode* swapPairsRecursively(ListNode* left, ListNode* right) {
        if(left == nullptr) {
            return NULL;
        }
        if(right == nullptr) {
            return left;
        }
        ListNode* left_next = right->next;
        right->next = left;
        if(left_next) {
             left->next = swapPairsRecursively(left_next, left_next->next);
        } else {
            left->next = NULL;
        }
       
        return right;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        
        return swapPairsRecursively(head, head->next);
    }
};
