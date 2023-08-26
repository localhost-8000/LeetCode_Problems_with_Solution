// Problem link:- https://leetcode.com/problems/split-linked-list-in-parts/
// Difficulty:- Medium


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int n = 0;
        
        ListNode *temp = head;
        while(temp) {
            n++;
            temp = temp->next;
        }
        
        temp = head;
        
        if(n < k) {
            k -= n;
            while(n--) {
                ans.push_back(temp);
                temp = temp->next;
                
                ans.back()->next = nullptr;
            }
            
            while(k--) {
                ans.push_back(nullptr);
            }
            
        } else {
            int rem = n % k;
            int p = n / k;
            
            ListNode *temp1 = temp;
            
            while(k--) {
                ans.push_back(temp);
                int len = p;
                
                if(rem) {
                    len++;
                    rem--;
                }
                
                while(len--) {
                    temp1 = temp;
                    temp = temp->next;
                }
                
                temp1->next = nullptr;
            }
        }
        
        return ans;
    }
};
