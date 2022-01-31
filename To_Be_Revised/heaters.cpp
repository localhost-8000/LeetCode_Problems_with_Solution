// Problem link:- https://leetcode.com/problems/heaters


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int houses_len = houses.size();
        int heaters_len = heaters.size();
        
        vector<int> min_dist(houses_len, INT_MAX);
        
        int i = 0, j = 0;
        while(i < houses_len && j < heaters_len) {
            if(houses[i] <= heaters[j]) {
                min_dist[i] = heaters[j] - houses[i];
                i++;
            }
            else {
                j++;
            }
        }
        
        i = houses_len - 1, j = heaters_len - 1;
        while(i >= 0 && j >= 0) {
            if(houses[i] >= heaters[j]) {
                min_dist[i] = min(min_dist[i], houses[i] - heaters[j]);
                i--;
            } 
            else {
                j--;
            }
        }
        
        int min_radius = INT_MIN;
        for(const int &rad : min_dist) {
            min_radius = max(min_radius, rad);
        }
        
        return min_radius;
    }
};
