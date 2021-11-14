// Problem link:- https://leetcode.com/problems/number-of-visible-people-in-a-queue/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(heights[n-1]);
        
        for(int i = n-2; i >= 0; --i) {
            int curr_height = heights[i];
            int cnt = 0;

            while(!st.empty() && curr_height > st.top()) {
                st.pop();
                cnt++;
            }
            ans[i] = cnt;
            ans[i] += (st.empty()) ? 0 : 1;
            st.push(curr_height);
        }
        
        // empty the stack..
        while(!st.empty()) {
            st.pop();
        }
        return ans;
    }
};
