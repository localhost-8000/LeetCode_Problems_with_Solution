// Problem link:- https://leetcode.com/problems/apply-discount-to-prices/
// Difficulty:- Medium

class Solution {
public:
    bool isPrice(string &str) {
        int n = str.length();
        if(n == 1) return false;
        if(str[0] != '$') return false;
        
        for(int i=1; i<n; ++i) {
            if(str[i] == '$' || isalpha(str[i])) return false;
        }
        return true;
    }
    
    string applyDiscount(string &price, int dis) {
        price = price.substr(1);
        
        long long num = 0;
        for(char &c : price) num = (num * 10) + (c - '0');
        
        double ans = num - ((double)num / 100) * dis;
        ostringstream out;
        out.precision(2);
        out << std::fixed << ans;
     
        return "$" + out.str();
    }
    
    string discountPrices(string sentence, int discount) {
        vector<string> words;
        string s = "";
        for(char &c : sentence) {
            if(c == ' ') {
                words.push_back(s);
                s = "";
            } else {
                s += c;
            }
        }
        words.push_back(s);
        
        for(string &word : words) {
            if(isPrice(word)) {
                word = applyDiscount(word, discount);
            }
        }
        
        string ans = "";
        for(auto word : words) {
            ans += word;
            ans += " ";
        }
        ans.pop_back();
        
        return ans;
    }
};
