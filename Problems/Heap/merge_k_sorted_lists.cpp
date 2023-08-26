// Problem link:- https://leetcode.com/problems/merge-k-sorted-lists/
// Difficulty:- Hard


// O(N * logK)..
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root_head = new ListNode();
        ListNode* root = root_head;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        for(auto list : lists) {
            if(list) pq.push({list->val, list});
        }
        
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            root->next = new ListNode(curr.first);
            root = root->next;
            curr.second = curr.second->next;
            
            if(curr.second) pq.push({curr.second->val, curr.second});
        }
        
        return root_head->next;
    }
};
