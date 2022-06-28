// Problem link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Difficulty:- Medium

// O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        int buy, sell;
        int ans = 0, i = 0;
        
        while(i < n - 1) {
            while(i < n - 1 && prices[i + 1] <= prices[i]) i++;
            buy = prices[i];
            
            while(i < n - 1 && prices[i + 1] > prices[i]) i++;
            sell = prices[i];
            
            ans += sell - buy;
        }
        
        return ans;
    }
};
