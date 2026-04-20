class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> columns;
        unordered_map<int, unordered_set<char>> squares;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                char curr = board[i][j];
                if (curr == '.') {
                    continue;
                }

                // check row
                if (rows[i].count(curr)) {
                    return false;
                }
                rows[i].insert(curr);

                // check column
                if (columns[j].count(curr)) {
                    return false;
                }
                columns[j].insert(curr);

                // check square
                if (squares[(i / 3) * 3 + (j / 3)].count(curr)) {
                    return false;
                }
                squares[(i / 3) * 3 + (j / 3)].insert(curr);
            }
        }
        return true;
    }
};
