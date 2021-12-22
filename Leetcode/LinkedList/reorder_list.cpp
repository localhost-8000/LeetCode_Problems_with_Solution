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

//......................................

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr,*temp;
        while(head!=nullptr){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head,*fast = head,*prev = nullptr;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = head,*head2;
        if(fast){
            head2 = slow->next;
            slow->next = nullptr;
        }
        else{
            head2 = slow;
            prev->next = nullptr;
        }
        // reversing the other half of the list
        head2 = reverse(head2);        
        int turn = 1;
        ListNode *ans = new ListNode(0);
        ListNode* curr = ans;
        while(head1 or head2){
            if(turn){
                curr->next = head1;
                head1 = head1->next;
            }
            else{
                curr->next = head2;
                head2 = head2->next;
            }
            turn^=1;
            curr = curr->next;
        }
        if(head1)
            curr->next = head1;
    }
};
