// Problem link:- https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Difficulty:- Hard

// using merge sort technique
class Solution {
public:
    void mergeCount(vector<pair<int, int>>& arr, int l, int r, vector<int>& res) {
        if(l >= r) return;
        
        int mid = l + (r - l) / 2;
        mergeCount(arr, l, mid, res);
        mergeCount(arr, mid+1, r, res);
        
        vector<pair<int, int>> mergedArr;
        int left = l, right = mid + 1;
        int cnt = 0;
        
        while(left <= mid && right <= r) {
            if(arr[left].first > arr[right].first) {
                cnt++;
                mergedArr.push_back(arr[right]);
                right++; 
            } else {
                res[arr[left].second] += cnt;
                mergedArr.push_back(arr[left]);
                left++;
            }
        }
        
        while(left <= mid) {
            res[arr[left].second] += cnt;
            mergedArr.push_back(arr[left++]);
        }
        
        while(right <= r) mergedArr.push_back(arr[right++]);
        
        int start = l;
        for(auto node : mergedArr) arr[start++] = node;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        
        vector<pair<int, int>> newArr(n);
        for(int i=0; i<n; ++i) newArr[i] = {nums[i], i};
        
        mergeCount(newArr, 0, n-1, res);
        
        return res;
    }
};

// using pbds data structure..
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        ordered_set set;
        set.insert({nums[n-1], n-1});
        
        for(int i=n-2; i>=0; --i) {
            int num = nums[i];
            res[i] = set.order_of_key({num, i});
            set.insert({num, i});
        }
        
        return res;
    }
};
