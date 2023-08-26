// Problem link:- https://leetcode.com/problems/valid-triangle-number


class Solution {
public:
    int findValidTriplet(int low, int high, int key, vector<int>& nums) {
        int lb = low;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        int cnt = high < lb ? 0 : high - lb + 1;
        return cnt;
    }
    
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = 0;
        
        for(int i=0; i<n-2; ++i) {
            for(int j=i+1; j<n-1 && nums[i] != 0; ++j) {
                int sum = nums[i] + nums[j];
                ans += findValidTriplet(j+1, n-1, sum, nums);
            }
        }
        
        return ans;
    }
};


// avoiding redundant computations..
class Solution {
public:
    int findValidTriplet(int low, int high, int key, vector<int>& nums) {
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = 0;
        
        for(int i=0; i<n-2; ++i) {
            int k = i + 2;
            for(int j=i+1; j<n-1 && nums[i] != 0; ++j) {
                int sum = nums[i] + nums[j];
                k = findValidTriplet(k, n-1, sum, nums);
                ans += (k - j - 1);
            }
        }
        
        return ans;
    }
};


// more optimization by linear scan..
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = 0;
        
        for(int i=0; i<n-2; ++i) {
            int k = i + 2;
            for(int j=i+1; j<n-1 && nums[i] != 0; ++j) {
                int sum = nums[i] + nums[j];
                while(k < n && sum > nums[k]) k++;
                ans += k - j - 1;
            }
        }
        
        return ans;
    }
};
