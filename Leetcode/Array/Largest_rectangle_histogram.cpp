// Problem link:- https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        int left_smaller[n];
        int right_smaller[n];
        
        stack<int> st;
        
        // calculate left smaller..
        for(int i = 0; i < n; ++i) {
            int curr_height = heights[i];
            
            while(!st.empty() && heights[st.top()] >= curr_height) st.pop();
            
            left_smaller[i] = st.empty() ? 0 : st.top() + 1;
            
            st.push(i);
        }
        
        // clear stack..
        while(!st.empty()) st.pop();
        
        // calculate right smaller...
        for(int i = n - 1; i >= 0; --i) {
            int curr_height = heights[i];
            
            while(!st.empty() && heights[st.top()] >= curr_height) st.pop();
            
            right_smaller[i] = st.empty() ? n - 1 : st.top() - 1;
            
            st.push(i);
        }
        
        // calculate max_area...
        int max_area = INT_MIN;
        for(int i = 0; i < n; ++i) {
            int height = heights[i];
            int width = (right_smaller[i] - left_smaller[i] + 1);
            
            int curr_area = height * width;
            max_area = max(curr_area, max_area);
        }
        
        return max_area;
    }
};

// More space optimized solution...
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> st;
        int max_area = 0;
        
        for(int i = 0; i < n; ++i) {
            int curr = heights[i];
            
            while(!st.empty() && heights[st.top()] >= curr) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                
                int curr_area = height * width;
                max_area = max(max_area, curr_area);
            }
            
            st.push(i);
        }
        
        while(!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            
            int curr_area = height * width;
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
};
