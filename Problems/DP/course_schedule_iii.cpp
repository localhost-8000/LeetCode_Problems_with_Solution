// Problem link:- https://leetcode.com/problems/course-schedule-iii/
// Difficulty:- Hard

// DP approach but it will give TLE.. O(n * max_duration)
class Solution {
public:
    int solve(vector<vector<int>>& courses, int i, int dur, vector<vector<int>>& dp) {
        int n = courses.size();
        if(i >= n) return 0;
        if(dp[i][dur] != -1) return dp[i][dur];
        
        int pick = dur + courses[i][0] <= courses[i][1] ? 1 + solve(courses, i+1, dur + courses[i][0], dp) : 0;
        int leave = solve(courses, i+1, dur, dp);
        
        return dp[i][dur] = max(pick, leave);
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses), end(courses), [](const vector<int>& a, const vector<int>& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        int n = courses.size();
        vector<vector<int>> dp(n, vector<int>(courses[n-1][1]+1, -1));
        
        return solve(courses, 0, 0, dp);
    }
};

// Refer Heap folder for optimized approach....
