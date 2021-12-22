// Problem link:- https://leetcode.com/problems/reorder-list


class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        
        int node_cnt = 0;
        
        ListNode* temp = head;
        ListNode *prev = nullptr, *next, *reversedList;
        
        while(temp) {
            node_cnt++;
            ListNode* node = new ListNode(temp->val, prev);
            prev = node;
            temp = temp->next;
        }
        
        reversedList = prev;
        
        int loop_cnt = (node_cnt - 1) / 2;
        temp = head;
        
        while(loop_cnt--) {
            // insert last node from the reversed list to the next of current node..
            next = temp->next;
            
            ListNode *lastNode = reversedList;
            reversedList = reversedList->next;
            
            temp->next = lastNode;
            lastNode->next = next;
            
            temp = next;
        }
        
        if(node_cnt & 1) {
            temp->next = nullptr;
        } else {
            temp->next->next = nullptr;
        }
    }
};
