// Problem link:- 
// Difficulty:- Medium


struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
    
    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr;
    }
    
    void putValue(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }
    
    TrieNode* getNode(char ch) {
        return children[ch - 'a'];
    }
};

class Solution {
    vector<vector<string>> ans;
    TrieNode *root;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        
        for(string& product : products) {
            generateTrie(product);
        }
        
        string prefix = "";
        for(char& ch : searchWord) {
            prefix += ch;
            ans.push_back(searchTrie(prefix));
        }
        
        return ans;
    }
    
    void generateTrie(const string& str) {
        TrieNode *temp = root;
        for(char ch : str) {
            if(!temp->containsKey(ch)) temp->putValue(ch, new TrieNode());
            
            temp = temp->getNode(ch);
        }
        temp->isEnd = true;
    }
    
    vector<string> searchTrie(string& prefix) {
        vector<string> res;
        TrieNode* curr = root;
        
        for(char &ch : prefix) {
            if(!curr->containsKey(ch)) return res;
            curr = curr->getNode(ch);
        }
        
        findStringWithPrefix(curr, prefix, res);
        
        return res;
    }
    
    void findStringWithPrefix(TrieNode* curr, string& str, vector<string>& res) {
        if(res.size() == 3) return;
        
        if(curr->isEnd) res.push_back(str);
        
        for(int i=0; i<26; ++i) {
            if(curr->children[i] == nullptr) continue;
            
            str += (i + 'a');
            findStringWithPrefix(curr->getNode(i + 'a'), str, res);
            str.pop_back();
        }
        
        return;
    }
};
