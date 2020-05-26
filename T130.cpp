class Solution {
public:
    void dfs(vector<vector<char>> &board,int i,int j)
    {
        int m = board.size();
        int n = board[0].size();
        bool tmp = i < 0 || j < 0 || i >= m || j >= n;
        if(tmp || board[i][j] == 'X' || board[i][j] == '#') return;
        board[i][j] = '#';
        dfs(board,i,j-1);
        dfs(board,i,j+1);
        dfs(board,i+1,j);
        dfs(board,i-1,j);
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return ;
        int m = board.size();
        int n = board[0].size();
        if(m<=2 || n<=2) return;
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O')
                dfs(board,0,j);
            if(board[m-1][j] == 'O')
                dfs(board,m-1,j);
        }
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                dfs(board,i,0);
            if(board[i][n-1] == 'O')
                dfs(board,i,n-1);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};