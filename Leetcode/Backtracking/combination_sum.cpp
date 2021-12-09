// Problem link:- https://leetcode.com/problems/combination-sum

// Backtracking approach
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> track;
    int n;
public:
    void backtrack(vector<int>& candidates, int target, int i) {
        if(i >= n) return;
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(track);
            return;
        }
        int curr = candidates[i];
        track.push_back(curr);
        backtrack(candidates, target - curr, i);
        track.pop_back();
        backtrack(candidates, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        backtrack(candidates, target, 0);
        return ans;
    }
};
