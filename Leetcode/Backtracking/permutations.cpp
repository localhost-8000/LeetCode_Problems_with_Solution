// Problem link:- https://leetcode.com/problems/permutations

class Solution {
private:
    vector<vector<int>> ans;
public:
    void backtrackGeneratePermutation(vector<int>& arr, int left, int right) {
        if(left == right) {
            ans.push_back(arr);
            return;
        }
        for(int i=left; i<=right; ++i) {
            swap(arr[i], arr[left]);
            backtrackGeneratePermutation(arr, left + 1, right);
            swap(arr[i], arr[left]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        backtrackGeneratePermutation(nums, 0, n - 1);
        return ans;
    }
};
