// Problem link:- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// Basic approach..
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(k == 0) return head;
        
        int node_cnt = 0;
        ListNode* temp = head;
        
        while(temp != nullptr) {
            temp = temp->next;
            node_cnt++;
        }
        
        int i = 1;
        int last_idx = node_cnt - k + 1;
        temp = head;
        int start_val, end_val;
        
        while(temp != nullptr) {
            if(i == k) start_val = temp->val;
            if(i == last_idx) end_val = temp->val;
            
            temp = temp->next;
            i++;
        }
        
        temp = head;
        i = 1;
        while(temp != nullptr && i <= max(k, last_idx)) {
            if(i == k) temp->val = end_val;
            if(i == last_idx) temp->val = start_val;
            
            temp = temp->next;
            i++;
        }
        
        return head;
    }
};

// Improved approach..
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        
        ListNode *ptr1, *ptr2, *kth_ptr;
        ptr1 = head;
        ptr2 = head;
        
        while(k-- > 1) {
            ptr1 = ptr1->next;
        }
        
        kth_ptr = ptr1;
        ptr1 = ptr1->next;
        
        while(ptr1 != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        swap(kth_ptr->val, ptr2->val);
        
        return head;
    }
};
