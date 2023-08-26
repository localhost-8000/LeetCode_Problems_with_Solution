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

// using frequency bucket..
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> store;
        
        for(auto ch : s) store[ch]++;
        
        vector<char> freq[n + 1];
        
        for(auto [ch, count] : store) freq[count].push_back(ch);
        
        s = "";
        
        for(int i=n; i>0; --i) { 
            for(auto ch : freq[i])
                for(int cnt=i; cnt>0; --cnt) s += ch;
        }
        
        return s;
    }
};
