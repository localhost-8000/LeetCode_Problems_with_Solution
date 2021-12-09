// Problem link:- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> pos(2, -1);
        int n = arr.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int curr = arr[mid];
            
            if(curr == target) {
                if(arr[l] == target && arr[r] == target) break;
                if(arr[l] != target) l++;
                if(arr[r] != target) r--;
            }
            
            else if(curr > target) r--;
            else l++;
        }
        if(l > r) return pos;
        pos[0] = l;
        pos[1] = r;
        return pos;
    }
};
