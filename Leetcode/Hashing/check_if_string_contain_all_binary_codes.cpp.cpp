// Problem link:- 
// Difficulty:-

// Brute force method.. O(n*k + 2 ^ k)..
class Solution {
public:
    void generateCodes(vector<string>& codes, int n, string s) {
        if(n == 0) {
            codes.push_back(s);
            return;
        }
        
        generateCodes(codes, n - 1, s + '0');
        generateCodes(codes, n - 1, s + '1');
        
        return;
    }
    
    bool hasAllCodes(string str, int k) {
        int n = str.length();
        
        if(n-k+1 < pow(2, k)) return false;
        
        unordered_set<string> us;
        
        for(int i=0; i<=n-k; ++i) {
            string s = "";
            for(int j=i; j<i+k; ++j) s += str[j];
            us.insert(s);
        }
        
        vector<string> codes;
        generateCodes(codes, k, "");
        
        for(string code : codes) {
            if(us.find(code) == us.end()) return false;
        }
        
        return true;
    }
};

// Optimized.. O(n*k)
class Solution {
public:
    bool hasAllCodes(string str, int k) {
        int n = str.length();
        
        unordered_set<string> us;
        int total = 1 << k;
        
        for(int i=k-1; i<n; ++i) {
            string sub = str.substr(i-k+1, k);
            if(us.find(sub) == us.end()) {
                us.insert(sub);
                total--;
                
                if(total == 0) return true;
            }
        }
        
        return false;
    }
};

// More optimized.. O(n).. using binary code itself as hash key
class Solution {
public:
    bool hasAllCodes(string str, int k) {
        int n = str.length();
        int total = 1 << k;
        
        vector<bool> set(total, false);
        int allOne = total - 1;
        int hash = 0;
        
        for(int i=0; i<n; ++i) {
            hash = ((hash << 1) & allOne) | (str[i] - '0');
            if(i >= k - 1 && set[hash] == false) {
                set[hash] = true;
                total--;
                
                if(total == 0) return true;
            }
        }
        
        return false;
    }
};
