// Problem link:- https://leetcode.com/problems/single-element-in-a-sorted-array

// linear time approach..
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i += 2) {
            if(nums[i] != nums[i + 1]) return nums[i];
        }
        
        return nums[n - 1];
    }
};

// another linear approach...
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int ans = 0;
        for(const int& x : nums) ans ^= x;
        
        return ans;
    }
};

// logN time approach...
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = size(nums);
        int L = 0, R = n-1, mid;
        
        while(L <= R) {
            mid = (L + R) >> 1;
            bool isHalfEven = (mid-L) % 2 == 0;          // check length of each half is odd or even
			
            if(mid+1 < n && nums[mid] == nums[mid+1])    // case: 1
                if(isHalfEven) L = mid+2;
                else R = mid-1;
				
            else if(mid && nums[mid] == nums[mid-1])     // case: 2
                if(isHalfEven) R = mid-2;
                else L = mid+1;
				
            else return nums[mid];                       // case: 3
        }
        
        return -1;   // wont be reached since we will always find required element inside loop
    }
};
