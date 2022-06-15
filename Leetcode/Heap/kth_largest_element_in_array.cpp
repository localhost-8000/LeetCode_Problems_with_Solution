// Problem link:- https://leetcode.com/problems/kth-largest-element-in-an-array/
// Difficulty:- Medium


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> container;
        
        for(auto num : nums) {
            container.push(num);
            
            if(container.size() > k) container.pop();
        }
        
        return container.top();
    }
};
