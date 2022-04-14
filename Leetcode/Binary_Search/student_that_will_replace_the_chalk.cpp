// Problem link:- https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk


// Linear approach..
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        
        for(int &x : chalk) sum += x;
        
        k = k % sum;
        int ans;
        
        for(int i=0; i<n; ++i) {
            if(k < chalk[i]) {
                ans = i;
                break;
            }
            k -= chalk[i];
        }
        
        return ans;
    }
};

// Binary search approach with prefix sum
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> pre_sum(n, 0);
        pre_sum[0] = chalk[0];
        
        for(int i=1; i<n; ++i) pre_sum[i] = pre_sum[i-1] + chalk[i];

        k = k % pre_sum[n - 1];
        if(k == 0) return 0;
        
        int l=0, r=n-1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int diff = k - pre_sum[mid];
            
            if(diff == 0) return mid + 1;
            
            if(diff < 0) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
};
