// Problem link: https://leetcode.com/problems/merge-in-between-linked-lists/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* p1;
        ListNode* p2;
        int i=0;
        while(temp) {
            if(i == a - 1) {
                p1 = temp;
            }
            if(i == b) {
                p2 = temp;
                break;
            }
            i++;
            temp = temp->next;
        }
        p1->next = list2;
        temp = list2;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = p2->next;
        return list1;
    }
};
