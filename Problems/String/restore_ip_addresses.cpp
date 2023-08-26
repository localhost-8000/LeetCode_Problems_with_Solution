// Problem link:- https://leetcode.com/problems/restore-ip-addresses

class Solution {
    vector<string> ans;
public:
    
    void dfs(string str, string temp, int idx, int dots) {
        
        if(idx == str.size() && dots == 4){
            
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        if(str.size() - idx > (4 - dots) * 3) return;
        if(str.size() - idx < (4 - dots)) return;
        
        int num = 0;
        for(int i = idx; i < idx + 3; i++){
            
            num = num * 10 + (str[i] - '0');
            
            if(num <= 255){
                temp += str[i];
                dfs(str, temp + '.', i + 1, dots + 1);
            }
            
            if(num == 0) break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        string temp;
        
        dfs(s, temp, 0, 0); 
        
        return ans;
    }
};
