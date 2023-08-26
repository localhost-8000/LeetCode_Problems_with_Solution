// Problem link:- https://leetcode.com/problems/odd-even-linked-list/
// Difficulty:- Medium

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        
        ListNode *temp = head, *prev = head;
        ListNode *even_root = new ListNode(), *even;
        even = even_root;
        int cnt = 1;
        
        while(temp) {
            if(cnt & 1) {
                prev = temp;
            } else {
                even->next = temp;
                even = temp;
                prev->next = temp->next;
            }
            
            temp = temp->next;
            cnt++;
        }
        
        even->next = nullptr;
        prev->next = even_root->next;
        
        return head;
    }
};

// Cleaner code..
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        
        ListNode *odd = head, *even = head->next, *even_root = even;
        
        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = even_root;
        
        return head;
    }
};
