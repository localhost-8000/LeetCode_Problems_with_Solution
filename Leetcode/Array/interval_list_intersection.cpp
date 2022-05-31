// Problem link:- https://leetcode.com/problems/interval-list-intersections/
// Difficulty:- Medium

// Two pointer approach.. O(m + n)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size();
        int n2 = secondList.size();
        
        vector<vector<int>> ans;
        int i = 0, j = 0;
        
        while(i < n1 && j < n2) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            
            int curr_start = max(start1, start2);
            int curr_end = min(end1, end2);
            
            if(curr_end < curr_start) {
                if(end1 < start2) i++;
                else j++;
            } else {
                ans.push_back({curr_start, curr_end});
                if(curr_end == end1) i++;
                else j++;
            }
        }
        
        return ans;
    }
};

// Same but cleaner code
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size();
        int n2 = secondList.size();
        
        vector<vector<int>> ans;
        int i = 0, j = 0;
        
        while(i < n1 && j < n2) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            
            int curr_start = max(start1, start2);
            int curr_end = min(end1, end2);
            
            if(curr_start <= curr_end) ans.push_back({curr_start, curr_end});
            
            if(end1 < end2) i++;
            else j++;
        }
        
        return ans;
    }
};
