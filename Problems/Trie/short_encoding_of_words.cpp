// Problem link:- https://leetcode.com/problems/short-encoding-of-words/
// Difficulty:- Medium


// Using set..O(n*k*k)
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> us;
        for(string& word : words) us.insert(word);
        
        for(string& word : words) {
            int n = word.length();
            for(int i=1; i<n; ++i) us.erase(word.substr(i));
        }
        
        int ans = 0;
        for(string word : us) ans += word.length() + 1;
        
        return ans;
    }
};

// Using trie... O(n * k)
struct TrieNode {
    TrieNode* children[26];
    int count = 0;
    
    TrieNode* get(char c) {
        if(children[c - 'a'] == nullptr) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        
        return children[c - 'a'];
    }
};


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        map<TrieNode*, int> nodes;
        
        int n = words.size();
        for(int i=0; i<n; ++i) {
            string word = words[i];
            TrieNode* curr = trie;
            
            for(int j=word.length()-1; j>=0; --j) curr = curr->get(word[j]);
            nodes[curr] = i;
        }
        
        int ans = 0;
        for(auto [node, index] : nodes) {
            if(node->count == 0) ans += words[index].length() + 1;
        }
        
        return ans;
    }
};
