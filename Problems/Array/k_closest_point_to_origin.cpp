// Problem link:- https://leetcode.com/problems/k-closest-points-to-origin

class Solution {   
    struct myComp {
        bool operator()(const vector<int>& v1, const vector<int>& v2) {
            double dist1 = distanceToOrigin(v1);
            double dist2 = distanceToOrigin(v2);
            
            return dist1 < dist2;
        }
    };
public:
    static double distanceToOrigin(const vector<int>& v) {
        int x = abs(v[0]);
        int y = abs(v[1]);
        int sq = (x * x) + ( y * y);
        return sqrt(sq);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        
        priority_queue<vector<int>, vector<vector<int>>, myComp> pq;
        
        for(const auto arr : points) {
            if(pq.size() < k) {
                pq.push(arr);
                continue;
            }
            
            double curr_dist = distanceToOrigin(arr);
            double prev_dist = distanceToOrigin(pq.top());
            
            if(curr_dist < prev_dist) {
                pq.pop();
                pq.push(arr);
            }
        }
        
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
