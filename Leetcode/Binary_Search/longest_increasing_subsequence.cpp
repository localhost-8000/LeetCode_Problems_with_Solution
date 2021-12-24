// Problem link:- https://leetcode.com/problems/longest-increasing-subsequence


// first approach..O(N*N)..
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> lis(n , 1);
        int ans = 1;
        
        for(int i = 1; i < n; ++i) {
            int curr_num = nums[i];
            
            for(int j = i - 1; j >= 0; --j) {
                if(nums[j] < curr_num) lis[i] = max(lis[i], lis[j] + 1);
            }
            
            ans = max(ans, lis[i]);
        }
        
        return ans;
    }
};


// second approach...O(NlogN)..
class Solution {
public:
    int findUpperBound(const vector<int>& tail, int x) {
        int l = 0, r = tail.size() - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(tail[mid] >= x) r = mid;
            else l = mid + 1;
        }
        
        return r;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> tail;
        tail.push_back(nums[0]);
        
        for(int i = 1; i < n; ++i) {
            int curr = nums[i];
            
            if(curr > tail.back()) tail.push_back(curr);
            else {
                int idx = findUpperBound(tail, curr);
                tail[idx] = curr;
            }
        }
        
        int ans = tail.size();
        return ans;
    }
};
