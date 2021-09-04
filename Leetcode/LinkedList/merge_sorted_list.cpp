// Problem link: https://leetcode.com/problems/merge-two-sorted-lists
// Iterative approach...

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        while(l1 != nullptr) {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
        return ans->next;
    }
};

// Recursive approach..

class Solution {
public:
    ListNode* mergeList(ListNode*l1, ListNode* l2) {
        
        if(l1 == NULL) {
            return l2;
        }
        else if(l2 == NULL) {
            return l1;
        }
        
        if(l1->val <= l2->val) {
            l1->next = mergeList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeList(l1, l2->next);
            return l2;
        }
        return l1;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return mergeList(l1, l2);
    }
};
