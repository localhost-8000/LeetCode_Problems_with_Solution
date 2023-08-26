// Problem link:- https://leetcode.com/problems/maximal-rectangle


class Solution {  
public:
    void createHistogram(vector<int>& histo, const vector<char>& row) {
        int c = row.size();
        for(int i = 0; i < c; ++i) {
            int isValid = row[i] - '0';
            histo[i] = isValid ? histo[i] + 1 : 0;
        }
    }
    
    int largestAreaHistogram(const vector<int>& histo) {
        int n = histo.size();
        
        stack<int> st;
        int max_area = 0;
        
        for(int i = 0; i < n; ++i) {
            int curr = histo[i];
            while(!st.empty() && histo[st.top()] >= curr) {
                int height = histo[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                
                int curr_area = width * height;
                max_area = max(curr_area, max_area);
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            int height = histo[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            
            int curr_area = width * height;
            max_area = max(curr_area, max_area);
        }
        
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        
        vector<int> histo(n, 0);
        int max_area = 0;
        
        for(int r = 0; r < m; ++r) {
            createHistogram(histo, matrix[r]);
            int curr_area = largestAreaHistogram(histo);
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
};
