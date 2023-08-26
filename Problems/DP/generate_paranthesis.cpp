// first solution...plain recursion..
class Solution {
public:
    
    void generateP(vector<string>& ans, int open_b, int close_b, string curr) {
        if(open_b == close_b && open_b == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(open_b < 0 || close_b < 0) {
            return;
            
        }
        if(open_b == close_b) {
            generateP(ans, open_b - 1, close_b, curr + '(');
        }
         
        if(open_b < close_b) {
            generateP(ans, open_b - 1, close_b, curr + '(');
            generateP(ans, open_b, close_b - 1, curr + ')');
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateP(ans, n, n, "");
        return ans;
    }
};
