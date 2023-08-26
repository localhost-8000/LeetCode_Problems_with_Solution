// Problem link:- https://leetcode.com/problems/course-schedule-iii/
// Difficulty:- Hard

// O(N * logN)...
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses), end(courses), [](const vector<int>& a, const vector<int>& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        
        int n = courses.size();
        
        priority_queue<int> taken;
        int duration = 0;
        
        for(auto course : courses) {
            int curr = course[0];
            if(duration + curr <= course[1]) {
                duration += curr;
                taken.push(curr);
            } else {
                if(!taken.empty() && taken.top() > curr) {
                    duration += curr;
                    duration -= taken.top();
                    taken.pop();
                    taken.push(curr);
                }
            }
        }
        
        return taken.size();
    }
};
