// Problem link:- https://leetcode.com/problems/count-number-of-nice-subarrays
// Difficulty:- Medium

// Two pointer approach..
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       
        int odd_cnt = 0, cnt = 0, total = 0;
        int j = 0;
        
        for(int& num : nums) {
            if(num & 1) {
                odd_cnt++;
                
                if(odd_cnt >= k) {
                    cnt = 1;
                    while(!(nums[j++] & 1)) cnt++;
                    total += cnt;
                }
            }
            else if(odd_cnt >= k) total += cnt;
        }
        
        return total;
    }
};

// subarray with sum k approach..
class Solution {
public:
    int subarrayWithSumK(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int sum = 0, cnt = 0;
        
        for(int &num : nums) {
            sum += num;
            if(sum == k) cnt++;
            if(umap.find(sum - k) != umap.end()) cnt += umap[sum - k];
            
            umap[sum]++;
        }
        
        return cnt;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
       
        for(int &num : nums) {
            num = num & 1 ? 1 : 0;
        }
        
        return subarrayWithSumK(nums, k);
    }
};
