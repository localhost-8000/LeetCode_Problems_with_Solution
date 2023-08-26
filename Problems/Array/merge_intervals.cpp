// Problem link:- https://leetcode.com/problems/merge-intervals

class Solution {
public:
    static bool mycomp(const vector<int>& v1, const vector<int>& v2) {
        if(v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycomp);
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<int> temp(2, 0);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        
        int prev_end = temp[1];
        
        for(int i=1; i<n; ++i) {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            
            if(curr_start > prev_end) {
                ans.push_back(temp);
                temp[0] = curr_start;
                temp[1] = curr_end;
                prev_end = curr_end;
            }
            else {
                prev_end = max(prev_end, curr_end);
                temp[1] = prev_end;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
