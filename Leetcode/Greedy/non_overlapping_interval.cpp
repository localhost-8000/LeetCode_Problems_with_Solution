// Problem link:- https://leetcode.com/problems/non-overlapping-intervals/
// Difficulty:- Medium

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        int n = intervals.size();
        int cnt = 0;
        int prev_end = intervals[0][1];
        
        for(int i=1; i<n; ++i) {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            
            if(curr_start < prev_end) {
                cnt++;
                if(curr_end < prev_end) prev_end = curr_end;
            } else {
                prev_end = curr_end;
            }
        }
        
        return cnt;
    }
};
