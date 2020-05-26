class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string &word,int i,int j,int w)
    {
        if(board[i][j] != word[w]) return false;
        if(w == word.size()-1) return true;
        char tmp = board[i][j];
        board[i][j] = '\0';
        if((i>=1 && dfs(board,word,i-1,j,w+1))
         ||(j+1<=board[0].size()-1 && dfs(board,word,i,j+1,w+1))
         ||(i+1<=board.size()-1 && dfs(board,word,i+1,j,w+1))
         ||(j>=1 && dfs(board,word,i,j-1,w+1)))
            return true;
        board[i][j] = tmp;
        return false;
    }
};