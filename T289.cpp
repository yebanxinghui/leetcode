class Solution {
public:
    int countnum(vector<vector<int>> board, int row, int col)
    {
        int m = board.size();
        int n = board[0].size();
        vector<int> neighbors{0,1,-1};
        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(i == 0 && j == 0) continue;
                int r = (row + neighbors[i]);
                int c = (col + neighbors[j]);
                if ((r < m && r >= 0) && (c < n && c >= 0) && (abs(board[r][c]) == 1)) {
                    count += 1;
                }
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int> > v(board);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int tmp = countnum(board,i,j);
                if((tmp == 2 || tmp == 3) && board[i][j] == 1)
                    board[i][j] = 1;
                else if((tmp < 2 || tmp > 3) && board[i][j] == 1)
                    board[i][j] = -1;
                else if(tmp == 3 && board[i][j] == 0)
                    board[i][j] = 2;
            }
        }
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] > 0) {
                    board[row][col] = 1;
                } else {
                    board[row][col] = 0;
                }
            }
        }
    }
};