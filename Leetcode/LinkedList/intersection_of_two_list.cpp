// Problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/

// first approach..
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* root1 = headA;
        ListNode* root2 = headB;
        unordered_set<ListNode*> us;
        while(root1 != NULL) {
            us.insert(root1);
            root1 = root1->next;
        }
        while(root2 != NULL) {
            if(us.find(root2) != us.end()) {
                return root2;
            }
            root2 = root2->next;
        }
        return NULL;
    }
};

// TC: O(N + M)

// another approach..

class Solution {
public:
    int countNode(ListNode* root) {
        int cnt = 0;
        while(root != nullptr) {
            cnt++;
            root = root->next;
        }
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int count1 = countNode(headA);
        int count2 = countNode(headB);
        
        ListNode* root1 = headA;
        ListNode* root2 = headB;
        
        int diff = max(count1, count2) - min(count1, count2);
        if(count1 > count2) {
            while(diff) {
                root1 = root1->next;
                diff--;
            }
        } else {
            while(diff) {
                root2 = root2->next;
                diff--;
            }
        }
        
        while((root1 && root2) && (root1 != root2)) {
            root1 = root1->next;
            root2 = root2->next;
        }
        
        if(root1 && root2) {
            return root2;
        } else {
            return NULL;
        }
        
    }
};

// TC: O(max(N, M))
