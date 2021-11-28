// Problem link:- https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
private:
    vector<int> mask;
public:
    bool isUnique(const string& str) {
        vector<int> freq(26, 0);
        for(int i=0; i<str.length(); ++i) {
            if(freq[str[i] - 'a']) return false;
            freq[str[i] - 'a']++;
        }
        return true;
    }
    int countSetBit(int n) {
        int cnt = 0;
        while(n > 0) {
            cnt++;
            n &= (n - 1);
        }
        return cnt;
    }
    int createMask(const string& str) {
        int m = 0;
        for(int i=0; i<str.length(); ++i) {
            int j = str[i] - 'a';
            m |= (1 << j);
        }
        return m;
    } 
    
    int findMaxLen(const vector<string>& arr, int i, string str) {
        
        if(i >= arr.size()) return countSetBit(createMask(str));
        
        if(!isUnique(arr[i])) return findMaxLen(arr, i+1, str);
        int curr_mask = createMask(str);
        int canNotBeMerge = (mask[i] & curr_mask);
        if(canNotBeMerge) return findMaxLen(arr, i+1, str);
        
        return max(findMaxLen(arr, i+1, str+arr[i]), findMaxLen(arr, i+1, str));
    }
    
    int maxLength(vector<string>& arr) {
        for(int i=0; i<arr.size(); ++i) {
            int m = createMask(arr[i]);
            mask.push_back(m);
        }
        return findMaxLen(arr, 0, "");
    }
};
