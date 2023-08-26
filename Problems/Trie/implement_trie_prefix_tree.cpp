// Problem link:- https://leetcode.com/problems/implement-trie-prefix-tree/
// Difficulty:- Medium


struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
    
    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr;
    }
    
    void putValue(char ch, TrieNode *node) {
        children[ch - 'a'] = node;
    }
    
    TrieNode* getTrieNode(char ch) {
        return children[ch - 'a'];
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *head = root;
        for(auto chr : word) {
            if(!head->containsKey(chr)) head->putValue(chr, new TrieNode());
            head = head->getTrieNode(chr);
        }
        
        head->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *head = root;
        int n = word.length();
        
        for(int i=0; i<n; ++i) {
            char ch = word[i];
            if(!head->containsKey(ch)) return false;
            head = head->getTrieNode(ch);
        }
        
        return head->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode *head = root;
        int n = prefix.length();
        int i;
        
        for(i=0; i<n; ++i) {
            char ch = prefix[i];
            if(!head->containsKey(ch)) return false;
            head = head->getTrieNode(ch);
        }
        
        return i == n;
    }
};
