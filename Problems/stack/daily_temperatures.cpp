// Problem link:- https://leetcode.com/problems/daily-temperatures
// Difficulty:- Medium

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; --i) {
            int curr = temperatures[i];
            while(!st.empty() && temperatures[st.top()] <= curr) st.pop();
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }

        return ans;
    }
};
