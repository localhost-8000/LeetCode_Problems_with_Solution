// Problem link:- https://leetcode.com/problems/132-pattern
// Difficulty:- Medium

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        
        int s3 = INT_MIN;
        
        for(int i=n-1; i>=0; --i) {
            int curr = nums[i];
            if(curr < s3) return true;
            
            while(!st.empty() && curr > st.top()) {
                s3 = st.top();
                st.pop();
            }
            
            st.push(curr);
        }
        
        return false;
    }
};
