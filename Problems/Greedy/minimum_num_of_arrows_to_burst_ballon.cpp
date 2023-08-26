// Problem link:- https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
    static bool myComp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        
        if(n == 0 || n == 1) return n;
        
        sort(points.begin(), points.end(), myComp);
        
        int ans = 1;
        int prev_end = points[0][1];
        
        for(int i=1; i<n; ++i) {
            int curr_start = points[i][0];
            int curr_end = points[i][1];
            
            if(curr_start <= prev_end) continue;
            
            ans++;
            prev_end = curr_end;
        }
        
        return ans;
    }
};
