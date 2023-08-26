// Problem link:- https://leetcode.com/problems/design-add-and-search-words-data-structure


class WordDictionary {
    unordered_map<int, vector<string>> umap;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int n = word.length();
        umap[n].push_back(word);
    }
    
    bool search(string word) {
        int n = word.length();   
        for(const string &str : umap[n]) {
            if(checkEqual(str, word)) {
                return true;
            }
        }
        return false;
    }
    
    bool checkEqual(const string& a, const string& b) {
        int n = a.length();
        for(int i=0; i<n; ++i) {
            if(b[i] == '.') continue;
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};
