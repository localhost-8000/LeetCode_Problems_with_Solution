// Problem link: https://leetcode.com/problems/reverse-linked-list/

// Iterative approach...
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL)
        {
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* root = head;
        while(root) {
            ListNode* temp = root->next;
            root->next = prev;
            prev = root;
            root = temp;
        }
        
        return prev;
    }
};

// Recursive approach...
class Solution {
public:
    ListNode* recursiveReverse(ListNode* head, ListNode* prev) {
        if(head == nullptr) {
            return prev;
        }
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        return recursiveReverse(temp, prev);
    }
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = NULL;
        return recursiveReverse(head, prev);
    }   
};
