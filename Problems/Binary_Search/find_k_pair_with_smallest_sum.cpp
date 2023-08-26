// Problem link:- https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class Solution {
    struct myComp {
        bool operator()(const vector<int>& p1, const vector<int>& p2) {
            return p1[0] + p1[1] < p2[0] + p2[1];
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 =  nums2.size();
        vector<vector<int>> ans;
        if(n1 == 0 || n2 == 0) return ans;
        
        priority_queue<vector<int>, vector<vector<int>>, myComp> pq; // max heap with comparator function..
        
        for(int i=0; i<min(n1, k); ++i) {
            for(int j=0; j<min(n2, k); ++j) {
                int curr_sum = nums1[i] + nums2[j];
                
                vector<int> tmp;
                
                if(pq.size() < k) {
                    tmp.push_back(nums1[i]);
                    tmp.push_back(nums2[j]);
                    pq.push(tmp);
                }
                
                else if(curr_sum < pq.top()[0] + pq.top()[1]) {
                    pq.pop();
                    tmp.push_back(nums1[i]);
                    tmp.push_back(nums2[j]);
                    pq.push(tmp);
                }
            }
        }
        
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
