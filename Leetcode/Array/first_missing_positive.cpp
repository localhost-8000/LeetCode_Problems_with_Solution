// Problem link:- https://leetcode.com/problems/first-missing-positive/
// Difficulty:- Hard

// first approach...space and time O(N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> us;
        int n = nums.size();
        
        int maxN = INT_MIN;
        for(int i=0; i<n; ++i) {
            int curr = nums[i];
            if(curr > 0) us.insert(curr);
            maxN = (curr > 0) ? max(maxN, curr) : maxN;
        }
        
        int min_pos = 1;
        while(min_pos <= maxN) {
            if(us.find(min_pos) == us.end()) return min_pos;
            min_pos++;
        }

        return min_pos;
    }
};


// constant space solution...
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool isOne = false;
        
        for(int i=0; i<n; ++i) {
            int curr_elem = nums[i];
            
            isOne = curr_elem == 1 ? true : isOne;
            
            nums[i] = (curr_elem <= 0 || curr_elem > n) ? 1 : curr_elem;
        }
        
        if(!isOne) return 1;
        
        for(int i=0; i<n; ++i) {
            int indx = abs(nums[i]) - 1;
            nums[indx] = -abs(nums[indx]);
        }
        
        for(int i=0; i<n; ++i) {
            if(nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
