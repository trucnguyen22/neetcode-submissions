class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> sqrs;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;

                if (rows[i].find(board[i][j]) == rows[i].end()) rows[i].insert(board[i][j]);
                else return false;

                if (cols[j].find(board[i][j]) == cols[j].end()) cols[j].insert(board[i][j]);
                else return false;

                if (sqrs[(i/3) * 3 + (j/3)].find(board[i][j]) == sqrs[(i/3) * 3 + (j/3)].end())
                    sqrs[(i/3) * 3 + (j/3)].insert(board[i][j]);
                else return false; 
            }
        }
        return true;
    }
};
