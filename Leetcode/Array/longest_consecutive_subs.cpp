// Problem link:- https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> track;
        int n = nums.size();
        
        for(const int &x : nums) {
            track.insert(x);
        }
        
        int ans = 0;
        int cnt = 0;
        int prev = INT_MIN;
        
        for(const int &x : track) {
            if(prev == INT_MIN || (x - 1) != prev) {
                ans = max(ans, cnt);
                cnt = 1;
            } else {
                cnt++;
            }
            prev = x;
        }
        
        ans = max(ans, cnt);
        return ans;
    }
};

// little bit more optimization..
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> track;
        int n = nums.size();
        
        for(const int &x : nums) {
            track.insert(x);
        }
        
        int ans = 0;
        
        for(const int &x : track) {
            if(track.find(x - 1) == track.end()) {
                int curr = 1;
                int num = x;
                
                while(track.find(num + 1) != track.end()) {
                    num++;
                    curr++;
                }
                
                ans = max(ans, curr);
            }
        }
        
        return ans;
    }
};
