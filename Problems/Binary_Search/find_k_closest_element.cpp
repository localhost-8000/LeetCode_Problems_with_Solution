// Problem link:- https://leetcode.com/problems/find-k-closest-elements

// Two pointer approach..
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        
        int cnt = n;
        int l = 0, r = n - 1;
        
        while(l < r && cnt > k) {
            int left_d = abs(arr[l] - x);
            int right_d = abs(arr[r] - x);
            
            if(left_d <= right_d) r--;
            else l++;
            
            cnt--;
        }
        
        for(int i=l; i<=r; ++i) {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};
