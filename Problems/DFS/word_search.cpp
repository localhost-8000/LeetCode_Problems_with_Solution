// Problem link:- https://leetcode.com/problems/word-search/
// Difficulty:- Medium

class Solution {
public:
    bool wordFound(vector<vector<char>>& board, int i, int j, string word, int k) {
        int r = board.size();
        int c = r ? board[0].size() : 0;
        int n = word.length();
        
        if(k >= n) return true;
        if(i < 0 || i >= r) return false;
        if(j < 0 || j >= c) return false;
        
        if(board[i][j] != word[k]) return false;
        
        board[i][j] = '*';
        
        bool left = wordFound(board, i, j-1, word, k+1);
        bool right = wordFound(board, i, j+1, word, k+1);
        bool up = wordFound(board, i-1, j, word, k+1);
        bool down = wordFound(board, i+1, j, word, k+1);
        
        board[i][j] = word[k];
        
        return left || right || up || down;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = r ? board[0].size() : 0;
        
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(wordFound(board, i, j, word, 0)) 
                    return true;
            }
        }
        
        return false;
    }
};
