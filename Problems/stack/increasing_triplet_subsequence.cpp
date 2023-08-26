// Problem link:- https://leetcode.com/problems/increasing-triplet-subsequence/submissions/
// Difficulty:- Medium

// Brute force approach.. O(n*n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=1; i<n-1; ++i) {
            int curr = nums[i];
            int left = i-1, right = i + 1;
            
            while(left >= 0 && nums[left] >= curr) left--;
            while(right < n && nums[right] <= curr) right++;
            
            if(left >= 0 && right < n) return true;
        }
        
        return false;
    }
};

// using stack.. O(n) tc and sc
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> low(n, -1), high(n, -1);
        stack<int> st;
        st.push(0);
        
        for(int i=1; i<n-1; ++i) {
            if(nums[st.top()] < nums[i]) {
                low[i] = st.top();
            } else {
                st.push(i);
            }
        }
        
        while(!st.empty()) st.pop();
        st.push(n-1);
        
        for(int i=n-2; i>=0; --i) {
            if(nums[st.top()] > nums[i]) {
                high[i] = st.top();
            } else {
                st.push(i);
            }
        }
        
        for(int i=1; i<n-1; ++i) {
            if(low[i] != -1 && high[i] != -1) return true;
        }
        
        return false;
    }
};

// little bit optimization of space..
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> low(n, -1);
        int prev = 0;
        
        for(int i=1; i<n-1; ++i) {
            if(nums[prev] < nums[i]) {
                low[i] = prev;
            } else {
                prev = i;
            }
        }
        
        prev = n - 1;
        
        for(int i=n-2; i>=0; --i) {
            int curr_high = -1;
            if(nums[prev] > nums[i]) {
                curr_high = prev;
            } else {
                prev = i;
            }
            
            if(low[i] != -1 && curr_high != -1) return true;
        }
        
        return false;
    }
};

// Space optimization.. O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        
        for(int num : nums) {
            if(num <= a) a = num;
            else if(num <= b) b = num;
            else return true;
        }
        
        return false;
    }
};
