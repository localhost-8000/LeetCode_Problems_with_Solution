// Problem link:- 
// Difficulty:- Medium

// greedy with heap.. O(n * logn)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        if(n < 2) return n;
        
        priority_queue<int, vector<int>, greater<int>> largest;
        
        for(int i=0; i<n-1; ++i) {
            int next_height = heights[i + 1];
            int curr_height = heights[i];
            
            if(curr_height >= next_height) continue;
            
            int diff = next_height - curr_height;
            largest.push(diff);
            
            if(largest.size() > ladders) {
                bricks -= largest.top();
                largest.pop();
            }
            
            if(bricks < 0) return i;
        }
        
        return n - 1;
    }
};

// using map..
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        if(n < 2) return n;
        
        map<int, int> largest;
        
        for(int i=0; i<n-1; ++i) {
            int diff = heights[i+1] - heights[i];
            
            if(diff <= 0) continue;
            
            largest[diff]++;
            
            if(ladders-- <= 0) {
                bricks -= begin(largest)->first;
                if(!--begin(largest)->second) largest.erase(begin(largest));
            }
            
            if(bricks < 0) return i;
        }
        
        return n - 1;
    }
};
