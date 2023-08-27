// Problem link: https://leetcode.com/problems/frog-jump/

// Hint: If you are on a ith stone and you want to go to the next stone, you need the jump unit taken to reach the ith stone.


// Optimal solution. TC: O(n) SC: O(n)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = size(stones);

        // [curr_stone][prev_jump_unit] = status
        unordered_map<int, unordered_map<int, bool>> store;
        // to track avialability of stone position.
        unordered_set<int> us;

        for (int &stone : stones) us.insert(stone);

        store[0][0] = true;
        store[1][1] = true;
        
        for (int i=1; i<n; ++i) {
            int curr_stone = stones[i];

            if (store.find(curr_stone) == store.end()) continue;

            // iterate on previous jump taken to reach current stone
            for (auto [prev_jump, state] : store[curr_stone]) {
                int next_jump = curr_stone + prev_jump;

                // if on k - 1 jump, stone is available
                if (us.find(next_jump - 1) != us.end()) {
                    store[next_jump - 1][prev_jump - 1] = true;
                }
                // if on k jump, stone is available
                if (us.find(next_jump) != us.end()) {
                    store[next_jump][prev_jump] = true;
                }
                // if on k + 1 jump, stone is available
                if (us.find(next_jump + 1) != us.end()) {
                    store[next_jump + 1][prev_jump + 1] = true;
                }
            }
        }

        return store.find(stones[n-1]) != store.end() ? true : false;
    }
};