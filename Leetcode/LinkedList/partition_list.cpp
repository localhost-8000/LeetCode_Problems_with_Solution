// Problem link:- https://leetcode.com/problems/partition-list/
// Difficulty:- Medium


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;
        
        ListNode *smaller = nullptr, *greater = nullptr;
        ListNode *temp_sm = nullptr, *temp_gr = nullptr;
        
        while(head != nullptr) {
            int val = head->val;
            ListNode *newNode = new ListNode(val);
            
            if(val < x) {
                if(temp_sm == nullptr) {
                    smaller = newNode;
                    temp_sm = smaller;
                }
                else {
                    temp_sm->next = newNode;
                    temp_sm = temp_sm->next;
                }
            } else {
                if(temp_gr == nullptr) {
                    greater = newNode;
                    temp_gr = greater;
                } else {
                    temp_gr->next = newNode;
                    temp_gr = temp_gr->next;
                }
            }
            head = head->next;
        }
        
        if(smaller == nullptr) return greater;
        if(greater == nullptr) return smaller;
        
        temp_sm->next = greater;
        return smaller;
        
    }
};

// More cleaner code..
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;
        
        ListNode *smaller_head = new ListNode(0);
        ListNode *greater_head = new ListNode(0);
        ListNode *smaller = smaller_head, *greater = greater_head;
        
        while(head != nullptr) {
            int val = head->val;
            ListNode *newNode = new ListNode(val);
            
            if(val < x) {
                smaller->next = head;
                smaller = smaller->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            
            head = head->next;
        }
        
        greater->next = nullptr;
        smaller->next = greater_head->next;
        
        return smaller_head->next;
        
    }
};
