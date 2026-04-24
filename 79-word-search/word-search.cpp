class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m= board.size(), n= board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // If we find start of the word, kick off backtrack
                if(board[i][j]== word[0] && backtrack(i, j, board, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(int r, int c, vector<vector<char>>& board, string word, int index){
        if(index==word.size()) return true;

        // boundary and character match checks
        if(r<0 || r>= board.size() || c<0 || c>= board[0].size() || board[r][c]!= word[index]) return false;

        // Mark current cell as visited and explore in all 4 direction
        char temp= board[r][c];
        board[r][c]= '#';

        bool found=backtrack(r+1, c, board, word, index+1) ||
            backtrack(r-1, c, board, word, index+1) ||
            backtrack(r, c+1, board, word, index+1) ||
            backtrack(r, c-1, board, word, index+1);
        
        // Backtrack
        board[r][c]= temp;

        return found;
    }
};