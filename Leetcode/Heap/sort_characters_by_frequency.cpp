// Problem link:- https://leetcode.com/problems/sort-characters-by-frequency/
// Difficulty:-


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> store;
        
        for(auto ch : s) store[ch]++;
        
        priority_queue<pair<int, char>> pq;
        
        for(auto [ch, count] : store) pq.push({count, ch});
        
        s = "";
        
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            while(curr.first--) s += curr.second;
        }
        
        return s;
    }
};
