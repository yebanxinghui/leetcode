class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();

        int islandNum = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == '1')
                {
                    ++islandNum;
                    dfs(grid,i,j);
                }
            }
        }
        return islandNum;
        
    }
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(grid[i][j] == '0') return ;
        grid[i][j]='0';
        int row = grid.size();
        int col = grid[0].size();
        if(i-1>=0) dfs(grid,i-1,j);
        if(i+1<row) dfs(grid,i+1,j);
        if(j-1>=0) dfs(grid,i,j-1);
        if(j+1<col) dfs(grid,i,j+1);
    }
};