// Problem link:- https://leetcode.com/problems/reverse-nodes-in-k-group/
// Difficulty:- Hard


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        
        int n = 0;
        ListNode *temp = head;
        
        while(temp) {
            temp = temp->next;
            n++;
        }
        
        if(k > n) return head;
        
        int tt = n / k;
        bool isFirst = true;
        
        ListNode *newHead = head;
        temp = head;
        
        while(tt--) {
            ListNode *prev = nullptr;
            ListNode *tail = temp;
            
            int tm = k;
            while(tm--) {
                ListNode *next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }
            
            if(isFirst) {
                isFirst = false;
                newHead = prev;
                head = tail;
                continue;
            }
            
            head->next = prev; 
            head = tail;
        }
        
        if(temp) head->next = temp;
        return newHead;
    }
};
