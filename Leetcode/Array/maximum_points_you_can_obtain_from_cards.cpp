// Problem link:- 
// Difficulty:- Medium

// Using prefix sum.. O(K)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int pre_sum = 0, i;
        
        for(i=0; i<k; ++i) pre_sum += cardPoints[i];
        if(i == n) return pre_sum;
        
        int ans = pre_sum, suff_sum = 0;
        i = k - 1;
        
        for(int j=n-1; j>=n-k; --j) {
            suff_sum += cardPoints[j];
            pre_sum -= cardPoints[i--];
            
            ans = max(ans, suff_sum + pre_sum);
        }
        
        return ans;
    }
};
