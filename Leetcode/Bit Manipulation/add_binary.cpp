// Problem link: https://leetcode.com/problems/add-binary

class Solution {
public:
    
    int add (char a, char b, int carry) {
        int n1 = a - '0';
        int n2 = b - '0';
        return n1 + n2 + carry;
    }
    
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        
        while (i >= 0 && j >= 0) {
            int sum = add(a[i], b[j], carry);
            a[i] = (sum % 2) + '0';
            carry = sum / 2;
            i--;
            j--;
        }
        
        while (i >= 0) {
            int sum = add(a[i], '0', carry);
            a[i] = (sum % 2) + '0';
            carry = sum / 2;
            i--;
        }
        
        while (j >= 0) {
            int sum = add('0', b[j], carry);
            a.insert(0, to_string(sum % 2));
            carry = sum / 2;
            j--;
        }
        
        if(carry) {
            a.insert(0, "1");
        }
        
        return a;
    }
};
