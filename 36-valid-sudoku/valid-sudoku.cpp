

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        for (int i = 0; i < 9; i++) {
            map<char, int> m;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    m[board[i][j]]++;
                    if (m[board[i][j]] > 1) return false;
                }
            }
        }

     
        for (int i = 0; i < 9; i++) {
            map<char, int> m;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    m[board[j][i]]++;
                    if (m[board[j][i]] > 1) return false;
                }
            }
        }

     
        for (int block = 0; block < 9; block++) {
            map<char, int> m;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = 3 * (block / 3) + i;
                    int col = 3 * (block % 3) + j;
                    if (board[row][col] != '.') {
                        m[board[row][col]]++;
                        if (m[board[row][col]] > 1) return false;
                    }
                }
            }
        }

        return true;
    }
};
