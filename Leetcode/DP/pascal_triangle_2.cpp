// Problem link:- https://leetcode.com/problems/pascals-triangle-ii/

// TC:- O(n^2) SC:- O(rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        for(int i=1; i<=rowIndex; ++i) {
            if(i % 2 == 0) {
                row[i/2] += row[i/2 - 1];
                for(int j=i/2 - 1; j>0; --j) {
                    row[j] += row[j-1];
                    row[i-j] = row[j];
                }
            } else {
                for(int j=i/2; j>0; --j) {
                    row[j] += row[j-1];
                    row[i-j] = row[j];
                }
            }
            row[i] = 1;
        }
        return row;
    }
};
