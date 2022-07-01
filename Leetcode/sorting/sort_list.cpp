// Problem link:- https://leetcode.com/problems/sort-list/
// Difficulty:- Medium

// O(n * logn)
class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode *root = new ListNode(), *temp = root;
        
        while(head1 && head2) {
            if(head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        
        if(head1) temp->next = head1;
        else temp->next = head2;
        
        return root->next;
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* mid_prev = nullptr;
        while(head && head->next) {
            mid_prev = mid_prev == nullptr ? head : mid_prev->next;
            head = head->next->next;
        }
        ListNode* mid = mid_prev->next;
        mid_prev->next = nullptr;
        return mid;
    }
    
    ListNode* mergeSort(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* mid = findMiddle(head);
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(mid);
        
        return merge(left, right);
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
