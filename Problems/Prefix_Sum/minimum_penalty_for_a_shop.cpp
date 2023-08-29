// Problem link: https://leetcode.com/problems/minimum-penalty-for-a-shop
// Difficulty: Medium

// key point: if a shop is closed at ith hour
// Penalty = (count of 'N' from 0 to i - 1) + (count of 'Y' from i to n - 1)


// Optimal Solution
// TC: O(n)  SC: O(n)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        // track total count of hours upto current hour without customers
        vector<int> noCustomersHour(n, 0);

        for (int i=0; i<n; ++i) {
            noCustomersHour[i] += (i == 0) ? 0 : noCustomersHour[i-1];
            noCustomersHour[i] += (customers[i] == 'N') ? 1 : 0;
        }
    
        int customersHour = 0; // count of hours with customers
        int minTime = n;
        int minPenalty = noCustomersHour[n-1];

        for (int i=n-1; i>=0; --i) {
            customersHour += (customers[i] == 'Y') ? 1 : 0;
            int currPenalty = customersHour + noCustomersHour[i];
            currPenalty -= (customers[i] == 'N') ? 1 : 0;
            
            if (currPenalty <= minPenalty) {
                minPenalty = currPenalty;
                minTime = i;
            }
        }

        return minTime;
    }
};


// Space Optimized solution
// TC: O(n)  SC: O(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int minTime = 0;
        int minPenalty = 0;
        int currPenalty = 0;

        for (int i=0; i<n; ++i) {
            if (customers[i] == 'Y') {
                currPenalty -= 1;
            } else {
                currPenalty += 1;
            }

            if (currPenalty < minPenalty) {
                minPenalty = currPenalty;
                minTime = i + 1;
            }
        }

        return minTime;
    }
};