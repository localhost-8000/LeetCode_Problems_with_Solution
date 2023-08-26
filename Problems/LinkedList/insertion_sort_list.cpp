// Problem link:- https://leetcode.com/problems/insertion-sort-list/

// first approach...
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        ListNode* sortedList = new ListNode(head->val);
        
        head = head->next;
        
        while(head != nullptr) {
            
            ListNode* curr_node = head;
            int curr_value = curr_node->val;
            
            ListNode* sorted_head = sortedList;
            ListNode* prev = sortedList;
            
            while(sorted_head != nullptr && sorted_head->val < curr_value) {
                prev = sorted_head;
                sorted_head = sorted_head->next;
            }
            
            if(sorted_head == sortedList) {
                ListNode* temp = new ListNode(curr_value, sortedList);
                sortedList = temp;
            }
            else {
                ListNode* temp = new ListNode(curr_value, prev->next);
                prev->next = temp;
            }
            
            head = head->next;
            
        }
        
        return sortedList;
    }
};
