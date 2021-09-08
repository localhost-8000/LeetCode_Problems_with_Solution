// Problem link: https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp = l1;
        ListNode* prev = l2;
        while(l1 && l2) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum %10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
        }
        while(l2) {
            int sum = l2->val + carry;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            prev->next = node;
            prev = node;
            l2 = l2->next;
        }
        if(carry) {
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }
        return temp;
    }
};
