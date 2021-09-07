// Problem link: https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    bool palindrome(const vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while(left < right) {
            if(arr[left] != arr[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return palindrome(arr);
    }
};
