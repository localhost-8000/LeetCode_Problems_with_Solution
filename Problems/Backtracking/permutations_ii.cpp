// Problem link:- https://leetcode.com/problems/permutations-ii

// first approach..
class Solution {
    vector<vector<int>> ans;
    set<vector<int>> st;
public:
    void backtrackGenerate(vector<int>& arr, int left, int right) {
        if(left == right) {
            st.insert(arr);
            return;
        }
        
        for(int i=left; i <= right; ++i) {
            if(i > left && arr[i] == arr[left]) continue;
            swap(arr[i], arr[left]);
            backtrackGenerate(arr, left + 1, right);
            swap(arr[i], arr[left]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        backtrackGenerate(nums, 0, n - 1);
        for(auto &arr : st) ans.push_back(arr);
        return ans;
    }
};

// Optimized approach..
class Solution {
    vector<vector<int>> ans;
    unordered_map<int, int> umap;
public:
    void backtrackGenerate(int n, vector<int>& arr) {
        if(arr.size() == n) {
            ans.push_back(arr);
            return;
        }
        for(auto &itr : umap) {
            if(itr.second) {
                // include current
                arr.push_back(itr.first);
                itr.second--;
                backtrackGenerate(n, arr);
                // revert changes for next iteration...
                itr.second++;
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        for(int &x : nums) umap[x]++;
        vector<int> temp;
        backtrackGenerate(n, temp);
        return ans;
    }
};
