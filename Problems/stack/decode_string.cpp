// Problem link:- https://leetcode.com/problems/decode-string


class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        
        stack<int> mul_cnt;    // store string multiplier count
        stack<char> st;        // store characters
        
        int num = 0;   // multiplier num
		
        for(int i=0; i<n; ++i) {
            char curr = s[i];
			
            if(curr >= '0' && curr <= '9') num = (num * 10) + (curr - '0');
			
            else if(curr == '[') {
                mul_cnt.push(num);    // as format is k[] hence when '[' occurs number is completed
                num = 0;
                st.push(curr);
            }
            else if(curr == ']') {
                string str = "";   // collect chars between '[' and ']'
                while(!st.empty() && st.top() != '[') {
                    str += st.top();
                    st.pop();
                }
                st.pop();
				
                int cnt = mul_cnt.top();    // get multiplier..i.e. k
                mul_cnt.pop();
                
                reverse(str.begin(), str.end());   // as string received in reverse order from stack so reverse to get back original string..
				
                string res = "";
                while(cnt--) {
                    res += str;
                }
                
                for(const char &ch : res) st.push(ch);   // push res string to stack again..for processing
            }
            else st.push(curr);
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
		
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
