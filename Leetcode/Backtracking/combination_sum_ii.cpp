// Problem link:- https://leetcode.com/problems/combination-sum-ii

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> track;
    int n;
public:
    void backtrack(vector<int>& candidates, int target, int curr) {
        
        if(target == 0) {
            ans.push_back(track);
            return;
        }
        
        for(int next = curr; next < n; ++next) {
            if(next > curr && candidates[next] == candidates[next - 1]) continue;
            
            int include_curr = candidates[next];
            if(target - include_curr < 0) break;
            
            track.push_back(include_curr);
            backtrack(candidates, target - include_curr, next + 1);
            
            track.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
       
        backtrack(candidates, target, 0);
        return ans;
    }
};
