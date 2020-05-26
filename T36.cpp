class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = board.size();
        vector<vector<bool> > line (9, vector<bool>(9, false));
        vector<vector<bool> > row (9, vector<bool>(9, false));
        vector<vector<bool> > square (9, vector<bool>(9, false));
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                if (board[i][j] == '.')
                    continue;
                int val = board[i][j] - '1';
                if (line[i][val])
                    return false;
                else
                    line[i][val] = true;
                if (row[j][val])
                    return false;
                else
                    row[j][val] = true;
                int x = i / 3, y = j / 3;
                int s = x * 3 + y;
                if (square[s][val])
                    return false;
                else
                    square[s][val] = true;
            }
        }
        return true;
    }
};