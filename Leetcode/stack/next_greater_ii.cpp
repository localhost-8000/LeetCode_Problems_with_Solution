// Problem link:- https://leetcode.com/problems/next-greater-element-ii


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        
        // find index of max element in the array...
        int maxM = nums[0];
        int ind = 0;
        for(int i=1; i<n; ++i) {
            int curr = nums[i];
            if(curr > maxM) {
                maxM = curr;
                ind = i;
            }
        }
        
        // start iterating backward from the max element index..
        st.push(maxM);
        vector<int> ans(n, -1);
        int i = (n + ind - 1) % n;
        
        while(i != ind) {
            int curr = nums[i];
            
            while(!st.empty() && st.top() <= curr) st.pop();
            
            if(!st.empty()) ans[i] = st.top();
            
            st.push(curr);
            i = (n + i - 1) % n;
        }
        
        return ans;
    }
};
